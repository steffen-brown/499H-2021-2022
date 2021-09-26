#include "vex.h"

double reversed = false;

void forwardDrive() {
  DriveLB.spin(forward, (Controller.Axis3.position(percent)/8.34) + (Controller.Axis1.position(percent)/8.34), voltageUnits::volt);
  DriveLF.spin(forward, (Controller.Axis3.position(percent)/8.34) + (Controller.Axis1.position(percent)/8.34), voltageUnits::volt);
  DriveRB.spin(forward, (Controller.Axis3.position(percent)/8.34) - (Controller.Axis1.position(percent)/8.34), voltageUnits::volt);
  DriveRF.spin(forward, (Controller.Axis3.position(percent)/8.34) - (Controller.Axis1.position(percent)/8.34), voltageUnits::volt);
}

void backwardDrive() {
  DriveLB.spin(reverse, (Controller.Axis3.position(percent)/8.34) - (Controller.Axis1.position(percent)/8.34), voltageUnits::volt);
  DriveLF.spin(reverse, (Controller.Axis3.position(percent)/8.34) - (Controller.Axis1.position(percent)/8.34), voltageUnits::volt);
  DriveRB.spin(reverse, (Controller.Axis3.position(percent)/8.34) + (Controller.Axis1.position(percent)/8.34), voltageUnits::volt);
  DriveRF.spin(reverse, (Controller.Axis3.position(percent)/8.34) + (Controller.Axis1.position(percent)/8.34), voltageUnits::volt);
}

void switchReversed() {
  reversed = false;
}

void switchForward() {
  reversed = true;
}

void driveTrainController() {
  if(reversed) {
    backwardDrive();
    Controller.Screen.clearLine(0);
    Controller.Screen.setCursor(0, 0);
    Controller.Screen.print("Reversed: Yes");
  } else {
    forwardDrive();
    Controller.Screen.clearLine(0);
    Controller.Screen.setCursor(0, 0);
    Controller.Screen.print("Reversed: No");
  }

  Controller.ButtonUp.pressed(switchForward);
  Controller.ButtonDown.pressed(switchReversed);

}