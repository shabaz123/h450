// Motor450.h
// rev 1 - Sep 2023 - shabaz - converted to an Arduino library

#ifndef MOTOR450_H
#define MOTOR450_H

#include "Arduino.h"

// defines
#define PWMWRITE analogWrite
// use .stop(HARD_BRAKE) to stop the motor quickly
// otherwise, use .stop() to coast to a stop.
#define HARD_BRAKE 1


// class definition
class Motor450
{
  public:
    // Motor450 objects require two PWM-capable pins
    Motor450(byte driverPin1, byte driverPin2);
    // Run the motor with direction [0..1] and speed [0..255]
    void run(byte direction, byte speed);
    // Stop the motor. If brake value is 1 then motor is rapidly halted
    void stop(byte brake);
    void stop();
  private:
    byte mDriverPin1;
    byte mDriverPin2; 
};

#endif // MOTOR450_H
