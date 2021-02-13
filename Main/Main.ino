#include <Servo.h>

#include "Joint.h" // <- where most of the other code is, see the two files "Joint.h" and "Joint.cpp"

//---------------------------------------------------------------
//---------------------------variables---------------------------
//---------------------------------------------------------------

const byte shortLed = 15;
const byte longLed = 16;

// instanciation

Joint pincer ( 8 , 25 );
Joint wrist ( 9 ,  60 );
Joint loreArm ( 10 , 60 );
Joint forArm( 11 , 60 );
Joint forArmRot( 12 , 90 );
Joint sholder( 13 , 90 );

//---------------------------------------------------------------
//---------------------------setup---------------------------
//---------------------------------------------------------------

void setup() {
  // put your setup code here, to run once:
    
    Serial.begin(9600); 
    pincer.setup();
    wrist.setup();
    loreArm.setup();
    forArm.setup();
    forArmRot.setup();
    sholder.setup();
    Serial.println("pincer setup finished");
    delay (2000);

}

//---------------------------------------------------------------
//---------------------------Loop---------------------------
//---------------------------------------------------------------

void loop() {

  pincer.loop();
  wrist.loop();
  loreArm.loop();
  forArm.loop();
  forArmRot.loop();
  sholder.loop();

}
