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
void loop(void)
{
   
   static int motorAngle = startingAngle;
   static int motorRotateAmount = rotationSpeed;

  motor.write(motorAngle);
  delay(10);
  SerialOutput(motorAngle, CalculateDistance());

  motorAngle += motorRotateAmount;
  if (motorAngle <= minimumAngle || motorAngle >= maximumAngle) {
    motorRotateAmount = -motorRotateAmount;
  }
  
}
int CalculateDistance(void)
{

 //Store Last Button State
   lastButton = curButton;

   //Read Current Button
   curButton = digitalRead(buttonPin);
  digitalWrite(TriggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TriggerPin, LOW);
  long duration = pulseIn(EchoPin, HIGH);
  float distance = ((duration / 2) * 0.0344) - .30;
if(distance >0&&distance<50)
{
  digitalWrite(redPin,HIGH);
  tone(buzzer,HIGH);
 
  
}
else if(curButton == HIGH && lastButton == LOW)
{noTone(buzzer);
  digitalWrite(redPin,LOW);
  digitalWrite(greenPin,HIGH);
  delay(1000);
  digitalWrite(greenPin,LOW);
}
    return int(distance);
    

}
void SerialOutput(const int angle, const int distance)
{
  String angleString = String(angle);
  String distanceString = String(distance);
  Serial.println(angleString + "," + distanceString);
}
