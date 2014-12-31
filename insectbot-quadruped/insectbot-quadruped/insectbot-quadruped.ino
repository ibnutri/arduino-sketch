// Servo Library 
#include <Servo.h>
// Servo name
Servo frontServo;
Servo rearServo;
// time delay between steps
int walkSpeed = 500;
// center servos
int centerPos = 90;
// servo angles for walking pattern
int frontRightUp = 70;
int frontLeftUp = 110;
int backRightForward = 70;
int backLeftForward = 110;
// another center position 
int centerTurnPos = 81;
// servo angles for walking pattern
int frontTurnRightUp = 70;
int frontTurnLeftUp = 110;
int backTurnRightForward = 70;
int backTurnLeftForward = 110;

// Variables for counters
int i;
int f;
int r;

void setup()
{
  pinMode(13, OUTPUT);
// attach servos
  frontServo.attach(9);
  rearServo.attach(10);
  // assign sensor
//  pinMode(sensorPin, INPUT);
  // center servos
  frontServo.write(centerPos);
  rearServo.write(centerPos);
  // wait 3 seconds for start walking
  delay(3000);
  //Serial.begin(9600); // serial data setup
}
void loop(){
   moveForward();
  delay(walkSpeed/100);
}
void moveForward()
{  
  digitalWrite(13, HIGH);
  // loop for the servo angels to smoothen the steps
  for (f = 0; f < 39; f++){
   frontRightUp++; 
   backLeftForward--;
   frontServo.write(frontRightUp);
   rearServo.write(backLeftForward);
   delay(10);
  }
  // loop for the servo angels to smoothen the steps
  for (r = 0; r < 39; r++){
   frontRightUp--; 
   backLeftForward++;
   frontServo.write(frontRightUp);
   rearServo.write(backLeftForward);
   delay(10);
  } 
  digitalWrite(13, LOW);
//  delay(500);// berenti sebentar, btw this is what fried the arduino :| damn
}



