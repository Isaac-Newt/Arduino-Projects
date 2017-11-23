/*
 * This sketch checks the resistance of water,
 * stores that as a value, and produces a warning
 * if the value excedes the defined limit.  It
 * will also log the value(s) to the serial
 * monitor.
 *
 * Credit: Isaac List, 2017
 * For:  Logan High School Digital Electronics
 *       Water Purifier project
 */

 /*
  * LCD Setup:
  *
  * LCD RS pin to digital pin 12
  * LCD Enable pin to digital pin 11
  * LCD D4 pin to digital pin 5
  * LCD D5 pin to digital pin 4
  * LCD D6 pin to digital pin 3
  * LCD D7 pin to digital pin 2
  * LCD R/W pin to ground
  * LCD VSS pin to ground
  * LCD VCC pin to 5V
  */

#include <LiquidCrystal.h>

// Set up LCD pins
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Set up remaining pins
int saltPin = 6;
int cleanPin = 7;
int warnLight = 8;
int safeLight = 9;

// Define variables
int saltValue;
int cleanValue;

// setup pin modes
void setup() {
  pinMode(saltPin, INPUT);
  pinMode(cleanPin, INPUT);
  pinMode(warnLight, OUTPUT);
  pinMode(safeLight, OUTPUT);
  // Set up LCD
  lcd.begin(16, 2);
  // Test message
  lcd.print("Hello World");
}

// loop the needed functions
void loop() {
  checkClean();
  checkSalt();
  // May want a delay here, e.g
  // "delay(250);" for .25sec's
}

// Check salinity of clean water
void checkClean() {
  // check resistance of water
  cleanValue = digitalRead(cleanPin);

  // print value of clean water to serial monitor and LCD
  Serial.print(cleanValue);
  lcd.print(cleanValue);

  // what to do based on cleanValue
  if (cleanValue >= 2) {
    digitalWrite(safeLight, LOW);
    flashWarnLight();
  }
  else if (cleanValue <= 2) {
    digitalWrite(warnLight, LOW); // turn off warning light if on
    digitalWrite(safeLight, HIGH); // turn on "safe" light
  }
}

// Check salinity of salt water
void checkSalt() {
  // check resistance of saltwater
  saltValue = digitalRead(saltPin);

  // print value of clean water to serial monitor and LCD
  Serial.print(saltValue);
  lcd.print(saltValue);

  // what to do based on saltValue
  // **Do we need any warnings for the saltwater?**
}

// Flash warning light at regular interval
void flashWarnLight() {
  digitalWrite(warnLight, HIGH);
  delay(250);
  digitalWrite(warnLight, LOW);
  delay(250);
}
