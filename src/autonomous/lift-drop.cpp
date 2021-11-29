#include "vex.h"

int liftdown() {
  setHeight = 2;
  wait(400, timeUnits::msec);
  setHeight = 0;
  return 0;
}

void dropLift() {
  task dropLiftTask(liftdown);
}