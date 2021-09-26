#include "vex.h"

int preset[5] = {0, -500, -1000, -1800, -2000};
int setHeight = 0;

int liftControllerTask() {
  while(true) {
    if((LiftL.rotation(rotationUnits::raw) + LiftR.rotation(rotationUnits::raw)) / 2 > preset[setHeight]) {
      LiftL.spin(reverse, 8, voltageUnits::volt);
      LiftR.spin(reverse, 8, voltageUnits::volt);
    }
    else if((LiftL.rotation(rotationUnits::raw) + LiftR.rotation(rotationUnits::raw)) / 2 < preset[setHeight]) {
      LiftL.spin(forward, 12, voltageUnits::volt);
      LiftR.spin(forward, 12, voltageUnits::volt);
    }
    else {
      LiftL.stop(brakeType::hold);
      LiftR.stop(brakeType::hold);
    }
  }
  return 0;
}

void lowerLift() {
  if(setHeight > 0) {
    setHeight--;
  }
}

void raiseLift() {
  if(setHeight < 4) {
    setHeight++;
  }
}

void liftController() {
  Controller.ButtonL2.pressed(lowerLift);
  Controller.ButtonR2.pressed(raiseLift);
}
