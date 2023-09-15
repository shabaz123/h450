// Motor450.cpp
// rev 1 - May 2023 - shabaz - original code
// rev 1.1 - May 2023 - shabaz - converted to an Arduino library

#include "Motor450.h"



// *************************************************
// ********  Motor450 class implementation  ********
// *************************************************

Motor450::Motor450(byte driverPin1, byte driverPin2)
:mDriverPin1(driverPin1), mDriverPin2(driverPin2)
{
  // Motor object constructor
  pinMode(mDriverPin1, OUTPUT);
  pinMode(mDriverPin2, OUTPUT);
  PWMWRITE(mDriverPin1, 0);
  PWMWRITE(mDriverPin2, 0);
}

void Motor450::run(byte direction, byte speed)
{
  if (direction==0) {
    PWMWRITE(mDriverPin2, 0);
    PWMWRITE(mDriverPin1, speed);
  } else {
    PWMWRITE(mDriverPin1, 0);
    PWMWRITE(mDriverPin2, speed);
  }
}

void Motor450::stop(byte brake)
{
  if (brake==0) {
    this->run(0,0);
  } else {
    PWMWRITE(mDriverPin1, 255);
    PWMWRITE(mDriverPin2, 255);
  }
}

void Motor450::stop()
{
  this->run(0,0);
}

// *************************************************
// ****   End of Motor450 class implementation  ****
// *************************************************

