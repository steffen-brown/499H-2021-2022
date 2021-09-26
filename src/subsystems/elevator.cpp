#include "vex.h"

void elevatorController() {
  if(Controller.ButtonA.pressing()) {
    Elevator.spin(forward, 10, voltageUnits::volt);
  } else if(Controller.ButtonB.pressing()) {
    Elevator.spin(reverse, 10, voltageUnits::volt);
  } else {
    Elevator.stop(brakeType::brake);
  }
}