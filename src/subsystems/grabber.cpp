#include "vex.h"

void grabberController() {
  if(ControllerSecondary.installed()) {
    if(ControllerSecondary.ButtonL1.pressing()) {
      Grabber.spin(reverse, 10, voltageUnits::volt);
    } else if(ControllerSecondary.ButtonR1.pressing()) {
      Grabber.spin(forward, 10, voltageUnits::volt);
    } else {
      Grabber.stop(hold);
    }
    if(ControllerSecondary.ButtonUp.pressing()) {
      setGrabber(0);
    } else if(ControllerSecondary.ButtonDown.pressing()) {
      setGrabber(1);
    }
  } else {
    if(Controller.ButtonL1.pressing()) {
      setGrabber(0);
    } else if(Controller.ButtonR1.pressing()) {
      setGrabber(1);
    }
  }
  
}