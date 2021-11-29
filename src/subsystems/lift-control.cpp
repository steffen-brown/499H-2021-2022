#include "vex.h"

int preset[4] = {-50, -900, -1300, -1800};
int setHeight = 0;
int give = 13;
bool liftResetting = false;

int liftControllerTask() {
  while(true) {

    if(!liftResetting) {
      if((LiftL.rotation(rotationUnits::raw) + LiftR.rotation(rotationUnits::raw)) / 2 > preset[setHeight] + give) {
        LiftL.spin(reverse, 8, voltageUnits::volt);
        LiftR.spin(reverse, 8, voltageUnits::volt);
      } else if((LiftL.rotation(rotationUnits::raw) + LiftR.rotation(rotationUnits::raw)) / 2 < preset[setHeight] - give) {
        LiftL.spin(forward, 5, voltageUnits::volt);
        LiftR.spin(forward, 5, voltageUnits::volt);
      }
      else {
        LiftL.stop(brakeType::hold);
        LiftR.stop(brakeType::hold);
      }
      /*
      if((abs((int)LiftL.rotation(rotationUnits::raw)) - abs((int)LiftR.rotation(rotationUnits::raw))) < -30) {
        LiftL.spin(reverse, 4, voltageUnits::volt);
        LiftR.spin(forward, 4, voltageUnits::volt);
      } else if((abs((int)LiftL.rotation(rotationUnits::raw)) - abs((int)LiftR.rotation(rotationUnits::raw))) > 30) {
        LiftL.spin(forward, 4, voltageUnits::volt);
        LiftR.spin(reverse, 4, voltageUnits::volt);
      }
      */
    }
    

    wait(10, timeUnits::msec);
  }

  
  return 0;
}

int resetLift() {
  LiftL.spin(forward, 5, voltageUnits::volt);
  LiftR.spin(forward, 5, voltageUnits::volt);
  liftResetting = true;
  wait(1000, timeUnits::msec);
  LiftL.resetPosition();
  LiftR.resetPosition();
  LiftL.stop(brakeType::hold);
  LiftR.stop(brakeType::hold);
  liftResetting = false;
  return 0;
}

void lowerLift() {
  if(setHeight > 0) {
    setHeight--;
  }
}

void raiseLift() {
  if(setHeight < 3) {
    setHeight++;
  }
}

void manualLiftReset() {
  task taskId2(resetLift);
}


void liftController() {
  Controller.ButtonL2.pressed(lowerLift);
  Controller.ButtonR2.pressed(raiseLift);
  Controller.ButtonRight.pressed(manualLiftReset);
  ControllerSecondary.ButtonRight.pressed(manualLiftReset);
}
