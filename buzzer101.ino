#include<Servo.h>
const int TriggerPin = 8;
const int EchoPin = 9;
const int motorSignalPin = 10;
const int buzzer = 12;
const int startingAngle = 90;
const int minimumAngle = 6;
const int maximumAngle = 175;
const int rotationSpeed = 1 ;
const int redPin = 2;
 const int greenPin = 3;
 const int bluePin = 4;
 const int buttonPin = 5;
 float curButton = HIGH;
 float lastButton = HIGH;
 int value;
 int toneOn;
 int increment = 10;
bool valid_distance;
Servo motor;
void setup(void)
{
  motor.attach(motorSignalPin);
  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  motor.attach(motorSignalPin);
   pinMode(redPin, OUTPUT);
   pinMode(greenPin, OUTPUT);
   pinMode(bluePin, OUTPUT);
   pinMode(buttonPin, INPUT);
   digitalWrite(buttonPin, HIGH);
   pinMode(buzzer,OUTPUT);
   DDRD = B11111111;
   Serial.begin(9600);
}


void loop() {
for(int i=700;i<800;i++){
  tone(buzzer,i);
  delay(15);
  }
  for(int i=800;i>700;i--){
  tone(buzzer,i);
  delay(15);
  }

}
