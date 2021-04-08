/*
  Analog Input
 Demonstrates analog input by reading an analog sensor on analog pin 0 and
 turning on and off a light emitting diode(LED)  connected to digital pin 11.
 Also triggers servo (on pin 9) for all your lightning dodging needs.
 
 The amount of time the LED will be on and off depends on
 the value obtained by analogRead().

 update maxThreshold so lightning falls within your screen's lightning output
 
 The circuit:
 * Potentiometer attached to analog input 0
 * center pin of the potentiometer to the analog pin
 * one side pin (either one) to ground
 * the other side pin to +5V
 * LED anode (long leg) attached to digital output 11
 * LED cathode (short leg) attached to ground
 * Servo attached to ground
 * Servo attached to +5v
 * Note: because most Arduinos have a built-in LED attached, the LED is optional.

 Created by David Cuartielles
 modified 05 April 2021
 By Laurel Taylor
 This example code is in the public domain.
 http://www.arduino.cc/en/Tutorial/AnalogInput
 */
#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int servoPin = 9;    // pin used to connect the servo
int sensorPin = A0;  // select the input pin for the light sensor
int ledPin = 11;     // select the pin for the LED (this is optional)
int sensorValue = 0; // variable to store the value coming from the sensor

// update this value to fit your screen. you may want it to put as high as 50, 
// depending on your screen brightness and how strong the resistor you're using is. 
int maxThreshold = 7; // 

void setup() {
  // attach Serial so you can see output under Serial Monitor
  Serial.begin(9600);
  
  // attaches the servo on pin to the servo object
  myservo.attach(servoPin);  
  // resets the angle of the servo
  myservo.write(20); 

  // for LED
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);

  if (sensorValue > 3) {
    // write the value if you think there will be lightning
    Serial.println(sensorValue);
  }
  
  if (sensorValue >= maxThreshold) {
    // Trigger the lightning!
    digitalWrite(ledPin, HIGH);
    myservo.write(0);  // push down the button
  
    delay(1000);  // simulate button press by waiting
    
    // reset the position
    digitalWrite(ledPin, LOW);
    myservo.write(20);                  
  }

  // please don't run super constantly:
  delay(10);
}