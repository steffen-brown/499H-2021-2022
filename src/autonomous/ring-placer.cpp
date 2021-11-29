#include "vex.h"

int desPos;

int autoPlace() {
  if(desPos == 2) {
    while(Grabber.rotation(rotationUnits::deg) > -300) {
      Grabber.spin(reverse, 8, voltageUnits::volt);
    }
  } else if(desPos == 1) {
    while(Grabber.rotation(rotationUnits::deg) > -280) {
      Grabber.spin(reverse, 8, voltageUnits::volt);
    }
  } else if(desPos == 0) {
    while(Grabber.rotation(rotationUnits::deg) < 20) {
      Grabber.spin(forward, 8, voltageUnits::volt);
    }
  }

  Grabber.stop(hold);

  return 0;
}

void setGrabber(int pos) {
  desPos = pos;
  task startPlace(autoPlace);
}