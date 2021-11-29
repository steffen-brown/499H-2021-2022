#include "vex.h"

bool locked = false;

void latchController() {
  if(Controller.ButtonX.pressing()) {
    Latch.spin(forward, 6, voltageUnits::volt);
    locked = false;
  } else if(Controller.ButtonB.pressing()) {
    Latch.spin(reverse, 6, voltageUnits::volt);
    locked = true;
  } else if(ControllerSecondary.ButtonR2.pressing()) {
    Latch.spin(forward, 6, voltageUnits::volt);
    locked = false;
  } else if(ControllerSecondary.ButtonL2.pressing()) {
    Latch.spin(reverse, 6, voltageUnits::volt);
    locked = true;
  } else {
    Latch.stop(hold);
  }
}