int analogPin = A0;   // KY-037 Analog Output
int ledPin1 = 8;
int ledPin2 = 7;
int ledPin3 = 6;
int ledPin4 = 5;
int analogVal;        // Analog Sound Level

const int soundThreshold = 7;  // Adjust based on Serial Monitor readings

// Duration for the roulette to spin (5 seconds)
const unsigned long rouletteDuration = 5000;

void setup() {
  pinMode(analogPin, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  analogVal = analogRead(analogPin);  // Read analog sound level

  if (analogVal > soundThreshold) {  // Adjust this value for better detection
    digitalWrite(ledPin1, HIGH);  // Turn LED ON
    delay(100);  // Prevent multiple triggers
    digitalWrite(8,HIGH);
    delay(100);
    digitalWrite(8,  LOW);
    delay(100);
    digitalWrite(7,HIGH);
    delay(100);
    digitalWrite(7,  LOW);
    delay(100);
    digitalWrite(6,HIGH);
    delay(100);
    digitalWrite(6,  LOW);
    delay(100);
    digitalWrite(5,HIGH);
    delay(100);
    digitalWrite(5,LOW);
    delay(100);
    digitalWrite(8,HIGH);
    delay(100);
    digitalWrite(8,  LOW);
    delay(100);
    digitalWrite(7,HIGH);
    delay(100);
    digitalWrite(7,  LOW);
    delay(100);
    digitalWrite(6,HIGH);
    delay(100);
    digitalWrite(6,  LOW);
    delay(100);
    digitalWrite(5,HIGH);
    delay(100);
    digitalWrite(5,LOW);
    delay(100);
    digitalWrite(8,HIGH);
    delay(100);
    digitalWrite(8,  LOW);
    delay(100);
    digitalWrite(7,HIGH);
    delay(100);
    digitalWrite(7,  LOW);
    delay(100);
    digitalWrite(6,HIGH);
    delay(100);
    digitalWrite(6,  LOW);
    delay(100);
    digitalWrite(5,HIGH);
    delay(100);
    digitalWrite(5,LOW);
    delay(100);
    digitalWrite(8,HIGH);
    delay(100);
    digitalWrite(8,  LOW);
    delay(100);
    digitalWrite(7,HIGH);
    delay(100);
    digitalWrite(7,  LOW);
    delay(100);
    digitalWrite(6,HIGH);
    delay(100);
    digitalWrite(6,  LOW);
    delay(100);
    digitalWrite(5,HIGH);
    delay(100);
    digitalWrite(5,LOW);
    delay(100);
    digitalWrite(8,HIGH);
    delay(100);
    digitalWrite(8,  LOW);
    delay(100);
    digitalWrite(7,HIGH);
    delay(100);
    digitalWrite(7,  LOW);
    delay(100);
    digitalWrite(6,HIGH);
    delay(100);
    digitalWrite(6,  LOW);
    delay(100);
    digitalWrite(5,HIGH);
    delay(100);
    digitalWrite(5,LOW);
    delay(100);
  } else {
    digitalWrite(ledPin1, LOW);  // Turn LED OFF
    digitalWrite(ledPin2, LOW); 
    digitalWrite(ledPin3, LOW); 
    digitalWrite(ledPin4, LOW); 
  }

  
}
