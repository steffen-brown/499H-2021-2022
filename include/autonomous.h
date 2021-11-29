#include "vex.h"

void linearPID(double rot, double reduction, bool drift);
void turnPID(double degrees, double reduction);

void setGrabber(int pos);

void preAuton(void);

void dropLift();

void nothing();

int timeOutTimer();