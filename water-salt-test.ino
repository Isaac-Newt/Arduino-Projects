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

// Set up pins
int saltPin = 1;
int cleanPin = 2;
int warnLight = 3;
int safeLight = 4;

/*
 * Would need to set up stuff for displaying on an
 * LCD display here as well.  Haven't done that yet.
 */

// Define variables
int saltValue;
int cleanValue;

// setup pin modes
void setup() {
  pinMode(saltPin, INPUT);
  pinMode(cleanPin, INPUT);
  pinMode(warnLight, OUTPUT);
  pinMode(safeLight, OUTPUT);
}

// loop the needed functions
void loop() {
  checkClean();
  checkSalt();
}

// Check salinity of clean water
void checkClean() {
  // check resistance of water
  cleanValue = digitalRead(cleanPin);

  // print value of clean water to serial monitor
  // replace this with an output to a display
  Serial.print(cleanValue);

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

  // print value of clean water to serial monitor
  // replace this with an output to a display
  Serial.print(saltValue);

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
