// h450-motor-example.ino
// rev 1 - May 2023 - shabaz


// *************************************************
// ******** Start of Motor Driver Code *************
// *************************************************
#define PWMWRITE analogWrite

class Motor
{
  public:
    // Motor objects require two PWM-capable pins
    Motor(byte driverPin1, byte driverPin2);
    // Run the motor with direction [0..1] and speed [0..255]
    void run(byte direction, byte speed);
    // Stop the motor. If optional brake value is 1 then motor is rapidly halted
    void stop(byte brake);
  private:
    

    byte mDriverPin1;
    byte mDriverPin2; 
};

Motor::Motor(byte driverPin1, byte driverPin2)
:mDriverPin1(driverPin1), mDriverPin2(driverPin2)
{
  // Motor object constructor
  pinMode(mDriverPin1, OUTPUT);
  pinMode(mDriverPin2, OUTPUT);
  PWMWRITE(mDriverPin1, 0);
  PWMWRITE(mDriverPin2, 0);
}

void Motor::run(byte direction, byte speed)
{
  if (direction==0) {
    PWMWRITE(mDriverPin2, 0);
    PWMWRITE(mDriverPin1, speed);
  } else {
    PWMWRITE(mDriverPin1, 0);
    PWMWRITE(mDriverPin2, speed);
  }
}

void Motor::stop(byte brake=0)
{
  if (brake==0) {
    this->run(0,0);
  } else {
    PWMWRITE(mDriverPin1, 255);
    PWMWRITE(mDriverPin2, 255);
  }
}

// *************************************************
// ********** End of Motor Driver Code *************
// *************************************************

// defines
#define FOREVER 1
#define DELAY_MS delay
#define HARD_BRAKE 1
#define MAX_SPEED 255
#define DIR_CW 0
#define DIR_CCW 1

// create Motor objects
Motor mymotor(9,10); 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  while(FOREVER) {
    Serial.print("run motor at top speed for 5 sec...\n");
    mymotor.run(DIR_CW, MAX_SPEED);
    DELAY_MS(5000);
    Serial.print("stop motor for 5 sec...\n");
    mymotor.stop();
    DELAY_MS(5000);
    Serial.print("reverse motor at top speed for 5 sec...\n");
    mymotor.run(DIR_CCW, MAX_SPEED);
    DELAY_MS(5000);
    Serial.print("hard brake motor for 5 sec...\n");
    mymotor.stop(HARD_BRAKE);
    DELAY_MS(5000);
    Serial.print("run motor at half speed for 5 sec...\n");
    mymotor.run(DIR_CW, 128);
    DELAY_MS(5000);
  }

}
