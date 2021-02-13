#ifndef Joint_h
#define Joint_h

#include "Arduino.h"
#include "servo.h"


class Joint {
    const int pin;
    const int homePosition;
    int currentPosition;

    int stepNum = 0;
    int nextStep;
    int numOfSteps = 50;
    float stepSize;

    Servo servo;

  public:
    int nextPosition;
    boolean isMoving = false ;

    Joint (int attachTo , int homeAngle); //constructor
    //~Joint(); // Destructor
    void setup();
    void loop();
    int updateNextStep ();
    void moveToNextStep ();
    void setNextPosition (int _nextPosition , int _numOfSteps );

};



#endif
