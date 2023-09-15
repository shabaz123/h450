// MotorTest.ino
// rev 1 - Sep 2023 - shabaz
// this code demonstrates the Motor450 library

// ******** includes ********
#include <Motor450.h>

// ******** defines ********
// defines
#define FOREVER 1
#define DELAY_MS delay
#define MAX_SPEED 255
// if the motor spins in the wrong direction, swap the 
// enumerations 0 and 1 in the following two lines
#define DIR_CW 0
#define DIR_CCW 1

// ********global variables ********
// create Motor object(s)
// The selected pins must be PWM-capable
Motor450 mymotor1(9,10);
Motor450 mymotor2(5,6); 

// ******** setup() function ********
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

}

// ******** loop() function ********
void loop() {
  // put your main code here, to run repeatedly:
  
  while(FOREVER) {
    // Motor 1 tests
    Serial.print("*** Motor # 1 tests ***\n");
    Serial.print("run motor at top speed for 5 sec...\n");
    mymotor1.run(DIR_CW, MAX_SPEED);
    DELAY_MS(5000);
    Serial.print("stop motor for 5 sec...\n");
    mymotor1.stop();
    DELAY_MS(5000);
    Serial.print("reverse motor at top speed for 5 sec...\n");
    mymotor1.run(DIR_CCW, MAX_SPEED);
    DELAY_MS(5000);
    Serial.print("hard brake motor for 5 sec...\n");
    mymotor1.stop(HARD_BRAKE);
    DELAY_MS(5000);
    Serial.print("run motor at half speed for 5 sec...\n");
    mymotor1.run(DIR_CW, 128);
    DELAY_MS(5000);
  }

}
