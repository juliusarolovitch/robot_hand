#include <Servo.h>
#define POTENTIOMETER_PIN A0


Servo myservo1;  // create servo object to control a servo
Servo myservo2;
Servo myservo5;
Servo myservo4;
Servo myservo3;
const int flexPin1 = A1;
const int flexPin2 = A2;
const int flexPin3 = A3;
const int flexPin4 = A4;
const int flexPin5 = A5;
float thumb_val;

int pos = 0;    // variable to store the servo position

void setup() {
  myservo1.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(7);
  myservo3.attach(5);
  myservo4.attach(8);
  myservo5.attach(6);
  
  thumb_val = 0;
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);
//  Serial.println(sensorValue);
  if (sensorValue>1000) {
    sensorValue = 1000;
  } else if (sensorValue<0) {
    sensorValue = 0;
  }
  pos = sensorValue*.18;
  int flexValue1 = analogRead(flexPin1);
  int flexValue2 = analogRead(flexPin2);
  int flexValue3 = analogRead(flexPin3);
  int flexValue4 = analogRead(flexPin4);
  int flexValue5 = analogRead(flexPin5);
  Serial.println(flexValue3);

  thumb_val = flexValue3*.18;
  if (thumb_val > 180) {
    thumb_val = 180;
  } else if (thumb_val < 0) {
    thumb_val = 0;
  }
  
  myservo1.write(180-thumb_val);
  myservo2.write(flexValue2*.18);
  myservo3.write(flexValue4*.18);
  myservo4.write(flexValue5*.18);
  myservo5.write(flexValue1*.18);

    
  delay(15);    
  
}
