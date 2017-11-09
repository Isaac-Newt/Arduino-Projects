// This program runs a traffic light cycle
// triggered by pressing a button like a 
// pedestrian would use to cross the street.

int button = 12;
int red = 10;
int yellow = 9;
int green = 8;
int flashred = 6;
int greenwalk = 5;

void setup(){
    pinMode(red, OUTPUT);
    pinMode(yellow, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(button, INPUT);
    pinMode(flashred, OUTPUT);
    pinMode(greenwalk, OUTPUT);
    digitalWrite(green, HIGH);
    digitalWrite(flashred, HIGH);
}

void loop() {
    if (digitalRead(button) == HIGH){
        delay(15); // software debounce
        if (digitalRead(button) == HIGH) {
            // if the switch is HIGH, ie. pushed down - change the lights!
            changeLights();
            delay(5000); // wait for 5 seconds
        }
    }
}

void changeLights(){
    // green off, yellow on for 3 seconds
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    delay(3000);

    // turn off yellow, then turn red on for 5 seconds
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    digitalWrite(greenwalk, HIGH);
    digitalWrite(flashred, LOW);
    delay(5000);

    // Change walk sign to flashing
    digitalWrite(greenwalk, LOW);
    for(int i=0; i<4; i++)
      flashRedLight();
    delay(50);

    // turn off red and yellow, then turn on green
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(flashred, HIGH);
    delay(3000);
}

void flashRedLight(){
    digitalWrite(flashred, HIGH);   
    delay(250);                       
    digitalWrite(flashred, LOW);    
    delay(250); 
}
