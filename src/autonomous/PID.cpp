#include "vex.h"

int timeOut = 0;

int timeOutTimer() {
  while(true) {
    timeOut++;
    wait(1, timeUnits::msec);
  }
}

double invertDegrees(double deg) {
  if(deg >= 180) {
    return deg - 180;
  } else {
    return deg + 180;
  }
}

void linearPID(double rot, double reduction, bool drift) {
  timeOut = 0;

  double linearkP = .025;
  double linearkI = 0.001;
  double linearkD = .0025;


  int linearError = 0;
  int linearPrevError = 0;
  int linearDerivative;
  int linearTotalError = 0;

  int stopTollerance = 10;
  double kDrift = 12;

  EncoderL.resetRotation();
  EncoderR.resetRotation();

  double intOrientation = Inertial.rotation();

  do {

    int leftEncoderPosition = EncoderL.position(rotationUnits::deg);
    int rightEncoderPosition = EncoderR.position(rotationUnits::deg);

    int averagePosition = (leftEncoderPosition + rightEncoderPosition) / 2;

    std::cout << linearError << "\n";

    linearError = rot - averagePosition;
    
    linearDerivative = linearError - linearPrevError;
    linearTotalError += linearError;

    double driveTrainMotorPower = linearError * linearkP + linearDerivative * linearkD + linearTotalError * linearkI;

    linearPrevError = linearError;

    double driftCounter;

    if(drift) { 
      if(rot < 0) {
       driftCounter = (Inertial.rotation() + intOrientation) * kDrift;
      } else {
        driftCounter = -1 * (Inertial.rotation() - intOrientation) * kDrift;
      }
    } else {
      driftCounter = 0;
    }
    

    DriveLB.spin(forward, (driveTrainMotorPower + driftCounter) / reduction, voltageUnits::volt);
    DriveLF.spin(forward, (driveTrainMotorPower + driftCounter) / reduction, voltageUnits::volt);
    DriveRB.spin(forward, (driveTrainMotorPower - driftCounter) / reduction, voltageUnits::volt);
    DriveRF.spin(forward, (driveTrainMotorPower - driftCounter) / reduction, voltageUnits::volt);
  
    wait(5, timeUnits::msec);
  }
  while((linearError > stopTollerance || linearError < -1*stopTollerance) && timeOut < 4000);
  
  DriveLB.stop(brake);
  DriveLF.stop(brake);
  DriveRB.stop(brake);
  DriveRF.stop(brake);
}

void turnPID(double degrees, double reducation) {
  double turnkP = .1;
  double turnkI = .00018;
  double turnkD = .00;


  int turnError = 0;
  int turnPrevError = 0;
  int turnDerivative;
  int turnTotalError = 0;

  int stopTollerance = 2;

  EncoderL.resetRotation();
  EncoderR.resetRotation();

  do {

    int currentPosition = Inertial.rotation();

    std::cout << turnError << "\n";

    turnError = degrees - currentPosition;
    
    turnDerivative = turnError - turnPrevError;
    turnTotalError += turnError;

    double driveTrainMotorPower = turnError * turnkP + turnDerivative * turnkD + turnTotalError * turnkI;

    turnPrevError = turnError;

    DriveLB.spin(forward, driveTrainMotorPower/reducation, voltageUnits::volt);
    DriveLF.spin(forward, driveTrainMotorPower/reducation, voltageUnits::volt);
    DriveRB.spin(reverse, driveTrainMotorPower/reducation, voltageUnits::volt);
    DriveRF.spin(reverse, driveTrainMotorPower/reducation, voltageUnits::volt);
  
    wait(5, timeUnits::msec);
  }
  while(turnError > stopTollerance || turnError < -1*stopTollerance);
  DriveLB.stop(brake);
  DriveLF.stop(brake);
  DriveRB.stop(brake);
  DriveRF.stop(brake);
}