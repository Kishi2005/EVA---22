#include "MotorDriver.h"

//Motore con led

int ledPin = 1; 
MotorDriver motor;

//Sensore di gas
int pin8 = 8;
int sensor = A0;
int sensorValue = 0;

//Sensore di luce

int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;

const int ledPin = 13;
 
void setup()
{
    //Motore con led
    
    pinMode(ledPin, OUTPUT);
    motor.begin();

    //Sensore di gas

    pinMode(pin8, OUTPUT);
    Serial.begin(9600);

    //Sensore di luce

    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, HIGH);

  while(millis() < 5000)
  {
    sensorValue = analogRead(A0);
    if(sensorValue > sensorHigh)
    {
      sensorHigh = sensorValue;
    }
    if(sensorValue < sensorLow)
    {
      sensorLow = sensorValue;
    }
  }
  digitalWrite(ledPin, LOW);
}
 
void loop()
{
    //Motore con led
    
    digitalWrite(ledPin, HIGH);
    delay(1000);
    motor.speed(0, 200);
    motor.speed(1, 200);            
    delay(1000);
    motor.brake(0);                 
    delay(1000);
    motor.speed(0, 100);
    motor.speed(1, -100);           
    delay(1000);
    motor.brake(0);
    motor.speed(0, 200);
    motor.speed(1, 200);
    motor.speed(0, 100);
    motor.speed(1, -100)
    motor.speed(0, 200);
    motor.speed(1, 200);
    motor.stop(0);                  
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(1000);

    //Sensore di gas

     sensorValue = analogRead(sensor);
  Serial.println(sensorValue, DEC);
  if (sensorValue > 500) {
    digitalWrite(pin8, HIGH);
  }
  else {
    digitalWrite(pin8, LOW);
  }

  //Sensore di luce 

  sensorValue = analogRead(A0);
  int pitch = 
  map(sensorValue, sensorLow, sensorHigh, 50, 4000);
  tone(8, pitch, 20);
  delay(10);
}
