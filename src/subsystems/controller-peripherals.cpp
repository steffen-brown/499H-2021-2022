#include "vex.h"

int controllerPeripherals() {
  while(true) {
    if(ControllerSecondary.installed()) {
      Controller.Screen.setCursor(1, 1);
      Controller.Screen.print("Control Type: Partner");
    } else {
      Controller.Screen.setCursor(1, 1);
      Controller.Screen.print("Control Type: Solo");
    }

    if(reversed) {
      Controller.Screen.setCursor(2, 1);
      Controller.Screen.print("Drivetrain: Reversed");
    } else {
      Controller.Screen.setCursor(2, 1);
      Controller.Screen.print("Drivetrain: Forward");
    }

    
    ControllerSecondary.Screen.setCursor(1, 1);
    ControllerSecondary.Screen.print("Lift: %d %d", (int)LiftL.temperature(temperatureUnits::celsius), (int)LiftR.temperature(temperatureUnits::celsius));

    ControllerSecondary.Screen.setCursor(2, 1);
    ControllerSecondary.Screen.print("Drive: %d %d", (int)DriveLF.temperature(temperatureUnits::celsius), (int)DriveRF.temperature(temperatureUnits::celsius));
    
    ControllerSecondary.Screen.setCursor(3, 1);
    ControllerSecondary.Screen.print("       %d %d", (int)DriveLB.temperature(temperatureUnits::celsius), (int)DriveRB.temperature(temperatureUnits::celsius));
    wait(50, timeUnits::msec);
  }
  return 0;
}