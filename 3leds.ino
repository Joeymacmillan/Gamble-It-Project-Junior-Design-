const int led1 = 8;  // LED 1 connected to Pin 8
const int led2 = 7;  // LED 2 connected to Pin 7
const int led3 = 6;  // LED 3 connected to Pin 6
const int button = 9; // Button connected to Pin 9

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(button) == HIGH) {  // press
    // Turn on the LEDs in sequence
    digitalWrite(led1, HIGH);  // LED for pin 8
    delay(500);  // Wait for 500ms
    digitalWrite(led1, LOW); //turn off led
    
    digitalWrite(led2, HIGH);  // LED for pin 7
    delay(500);  // Wait for 500ms
    digitalWrite(led2, LOW);   // tur off led
    
    digitalWrite(led3, HIGH);  // LED for pin 9
    delay(500);  // Wait for 500ms
    digitalWrite(led3, LOW);   // turn off led
  } else {
    // LEDS off when nothing pressed
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
}

//Joseph MacMillan 
