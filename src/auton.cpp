#include "vex.h"

class button {
  private:
    color buttonColor;
    color originalButtonColor;
    int xPos;
    int yPos;
    int width;
    int height;
    bool selected;

    std::string label;

  public:
    button(color Color, int x, int y, int w, int h, std::string lab) {
      buttonColor = Color;
      originalButtonColor = Color;
      xPos = x;
      yPos = y;
      width = w;
      height = h;
      label = lab;
      selected = false;
    }

    void setSelected() {
      buttonColor = green;
      selected = true;
    }

    void unselected() {
      buttonColor = originalButtonColor;
      selected = false;
    }

    bool getSelected() {
      return selected;
    }

    void updateButton() {
      if(Brain.Screen.xPosition() < xPos + width && Brain.Screen.xPosition() > xPos && Brain.Screen.yPosition() > yPos && Brain.Screen.yPosition() < yPos + height) {
        setSelected();
      } else {
        unselected();
      }

      Brain.Screen.drawRectangle(xPos, yPos, width, height, buttonColor);
      Brain.Screen.printAt(xPos + width/2 - 20, yPos + width/2 - 20, label.c_str());
    }
};

button leftAutonButton = button(red, 0, 0, 240, 175, "Left");
button rightAutonButton = button(blue, 240, 0, 240, 175, "Right");
button skillsAutonButton = button(yellow, 0, 175, 480, 75, "No Auton");

void updateScreen() {
  leftAutonButton.updateButton();
  rightAutonButton.updateButton();
  skillsAutonButton.updateButton();
}

void autonSelector() {
  Brain.Screen.pressed(updateScreen);
  leftAutonButton.updateButton();
  rightAutonButton.updateButton();
  skillsAutonButton.updateButton();
}

void preAuton(void) {
  Inertial.calibrate();
  autonSelector();
}

void nothing() {};

void autonomous() {
  LiftR.resetPosition();
  LiftL.resetPosition();

  Brain.Screen.clearScreen();
  Brain.Screen.pressed(nothing);
  
  task startTimer(timeOutTimer);
  
  if(rightAutonButton.getSelected()) {
    Brain.Screen.printAt(60, 60, "Right Auton Queued");
    dropLift();
    linearPID(-1950, 1, true);
    wait(450, timeUnits::msec);
    Latch.spin(reverse, 6, voltageUnits::volt);
    setHeight = 1;
    wait(300, timeUnits::msec);
    turnPID(-75, 1);
    linearPID(450, 8, true);
    turnPID(0, 1);
    linearPID(1500, 8, true);
    setHeight = 0;
    setGrabber(2);
    wait(1000, timeUnits::msec);
    linearPID(-263, 8, false);
    setGrabber(0);
  }

  if(leftAutonButton.getSelected()) {
    Brain.Screen.printAt(60, 60, "Left Auton Queued");
    dropLift();
    linearPID(-2170, 1, true);
    wait(300, timeUnits::msec);
    Latch.spin(reverse, 6, voltageUnits::volt);
    setHeight = 1;
    wait(300, timeUnits::msec);
    linearPID(1240, 3, true);
    turnPID(-50, 1);
    linearPID(620, 5, false);
    setGrabber(2);
    setHeight = 0;
    wait(500, timeUnits::msec);
    linearPID(-380, 5, false);
  }

  if(skillsAutonButton.getSelected()) {
    Brain.Screen.printAt(60, 60, "Skills Auton Queued");
    dropLift();
    wait(1500, timeUnits::msec);
    linearPID(-400, 8, false);
    Latch.spin(reverse, 12, voltageUnits::volt);
    turnPID(20, .25);
    setHeight = 1;
    linearPID(400, 3, false);
    turnPID(-90, 2);
    linearPID(-3000, 3, false);
    setHeight = 0;
    Latch.spin(forward, 12, voltageUnits::volt);
    wait(1500, timeUnits::msec);
    linearPID(300, 3, false);
    turnPID(-105, .5);
    linearPID(-500, 3, false);
    Latch.spin(reverse, 12, voltageUnits::volt);
    wait(1000, timeUnits::msec);
    setHeight = 1;
    linearPID(300, 3, false);
    turnPID(-130, .5);
    linearPID(1900, 5, false);
    linearPID(-100, 3, false);
    turnPID(0, 2);
    linearPID(-600, 5, false);
    setHeight = 3;
    turnPID(90, 2);
    linearPID(-1200, 2, false);
    Latch.spin(forward, 12, voltageUnits::volt);
    wait(1000, timeUnits::msec);
    linearPID(300, 5, false);
    turnPID(90, 2);
    linearPID(1700, 5, false);


    

    
  }

}