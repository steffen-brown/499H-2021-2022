#include "vex.h"

void usercontrol() {
  task taskId2(resetLift);
  task taskId3(controllerPeripherals);
  liftController();

  DriveLB.setBrake(coast);
  DriveRB.setBrake(coast);
  DriveLF.setBrake(coast);
  DriveRF.setBrake(coast);

  Controller.Screen.clearScreen();
  ControllerSecondary.Screen.clearScreen();

  Brain.Screen.clearScreen();
  Brain.Screen.pressed(nothing);

  while(true) {
    elevatorController();
    driveTrainController();
    grabberController();
    latchController();

    wait(5, timeUnits::msec);
  }
}