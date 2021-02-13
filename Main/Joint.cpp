
#include "Joint.h"

//--------------------------- Joints ---------------------------

Joint::Joint (int attachTo , int homeAngle) :
  pin(attachTo),
  homePosition(homeAngle) {}


void Joint::setup() {
  servo.attach(pin);
  servo.write(homePosition);
  currentPosition = homePosition;

}


void Joint::loop() {

//    Serial.print("isMoving = "); Serial.println(isMoving);

    if (isMoving == true) {
      updateNextStep ();
      moveToNextStep ();    
    }
}


int Joint::updateNextStep () {
  if (stepNum >= numOfSteps) {
    currentPosition = nextPosition;
    isMoving = false;
    Serial.println("movement finished");
  } else {
    nextStep = currentPosition + stepNum * stepSize;
    Serial.print("nextStep ="); Serial.println(nextStep);
    Serial.print("stepNum ="); Serial.println(stepNum);
    stepNum ++;
  }
}


void Joint::moveToNextStep () {
      servo.write(nextStep);
}


void Joint::setNextPosition (int _nextPosition , int _numOfSteps )  {
  Serial.println("setting nextPosition to ");Serial.println(_nextPosition);

  isMoving = true;
  nextPosition = _nextPosition;
  numOfSteps = _numOfSteps;
  stepNum = 0;
  Serial.print("isMoving = "); Serial.println(isMoving);

  stepSize = (nextPosition - currentPosition)/(numOfSteps - 1);
  Serial.print("stepsize ="); Serial.println(stepSize);
}
