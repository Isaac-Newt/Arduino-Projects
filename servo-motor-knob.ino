/*
 * This will control a servo motor's rotation
 * using a potentiometer.
 */

#include <Servo.h>

int potPin = 0;
int servoPin = 9;
Servo servo;

void setup() {
    servo.attach(servoPin);
}

void loop() {
    int reading = analogRead(potPin);
    int angle = reading / 6;
    servo.write(angle);
}
