#include "vex.h"

void usercontrol() {
  task taskId(liftControllerTask);

  while(true) {

    liftController();
    elevatorController();
    driveTrainController();
  }
}