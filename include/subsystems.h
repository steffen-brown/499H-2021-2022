#include "vex.h"

void liftController();
int liftControllerTask();
int resetLift();
extern int setHeight;

void elevatorController();

extern bool reversed;
void driveTrainController();

void grabberController();

int controllerPeripherals();

void latchController();