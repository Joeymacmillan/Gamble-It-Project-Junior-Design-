const int analogPin = A0;   // KY-037 Analog Output for sound detection

// Fixed threshold for sound detection
const int SOUND_THRESHOLD = 540;
const int ledPin4 = 5;

void setup() {
  // put your setup code here, to run once:
void playStartupSound();
pinMode(analogPin, INPUT);
pinMode(ledPin1, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
if (millis() - lastSoundCheckTime > 20) {
    int soundLevel = analogRead(analogPin);
    lastSoundCheckTime = millis();
      
      // Check for clap
      if (soundLevel > SOUND_THRESHOLD) {

        // Run the LED sequence as reward
        playLEDSequence();

        delay(1000);
        

    }
  }
}
void playLEDSequence() {
  digitalWrite(ledPin1, HIGH);
  delay(100);
  digitalWrite(ledPin1, LOW);
  delay(100);
}
