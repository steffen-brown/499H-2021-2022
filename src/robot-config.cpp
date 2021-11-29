#include "vex.h"

using namespace vex;

brain Brain;

motor DriveLB = motor(PORT1, ratio18_1, false);
motor DriveRB = motor(PORT2, ratio18_1, true);
motor DriveLF = motor(PORT18, ratio18_1, false);
motor DriveRF = motor(PORT4, ratio18_1, true);

motor LiftL = motor(PORT17, ratio18_1, false);
motor LiftR = motor(PORT16, ratio18_1, true);

motor Latch = motor(PORT8, ratio18_1, false);

motor Grabber = motor(PORT9, ratio36_1, false);

controller Controller = controller(primary);
controller ControllerSecondary = controller(partner);

encoder EncoderR = encoder(Brain.ThreeWirePort.A);
encoder EncoderL = encoder(Brain.ThreeWirePort.C);

inertial Inertial = inertial(PORT11);

void vexcodeInit(void) {
  LiftL.resetPosition();
  LiftL.resetPosition();
}