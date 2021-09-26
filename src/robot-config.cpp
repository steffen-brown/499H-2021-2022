#include "vex.h"

using namespace vex;

brain Brain;

motor DriveLB = motor(PORT1, ratio18_1, false);
motor DriveRB = motor(PORT2, ratio18_1, true);
motor DriveLF = motor(PORT5, ratio18_1, false);
motor DriveRF = motor(PORT4, ratio18_1, true);

motor LiftL = motor(PORT6, ratio18_1, false);
motor LiftR = motor(PORT7, ratio18_1, true);

motor Elevator = motor(PORT8, ratio18_1, false);

controller Controller = controller(primary);

encoder EncoderR = encoder(Brain.ThreeWirePort.A);
encoder EncoderL = encoder(Brain.ThreeWirePort.C);
encoder EncoderC = encoder(Brain.ThreeWirePort.E);

void vexcodeInit(void) {
  
}