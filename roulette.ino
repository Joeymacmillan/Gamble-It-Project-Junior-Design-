/*
 * Simple Clap Reaction Game with Fixed Threshold
 * Uses a simpler approach with fixed sensitivity values
 */

// Pin definitions
const int analogPin = A0;   // KY-037 Analog Output for sound detection
const int ledPin1 = 8;      // Sequence LEDs
const int ledPin2 = 7;
const int ledPin3 = 6;
const int ledPin4 = 5;
const int buzzerPin = 9;    // Buzzer/speaker for audio commands

// Fixed threshold for sound detection
const int SOUND_THRESHOLD = 200; 

// Game variables
int userScore = 0;
unsigned long timeLimit = 2000;         // Initial time limit (2 seconds)
unsigned long lastCommandTime = 0;      // When the last command was issued
unsigned long lastSoundCheckTime = 0;   // To avoid checking too often
bool waitingForResponse = false;
bool gameActive = true;
bool gameOver = false;                  // Flag to track game over state

// Function prototypes
void turnOffAllLEDs();
void playLEDSequence();
void playCommandSound();
void playFailSound();
void playStartupSound();
void issueNewCommand();

void setup() {
  pinMode(analogPin, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  
  // Make sure all LEDs are off at start
  turnOffAllLEDs();
  
  // Start the game
  // Play startup sound
  playStartupSound();
  delay(1000);
  
  // Issue first command
  issueNewCommand();
}

void loop() {
  // Read sound level every 20ms to avoid overwhelming the serial monitor
  if (millis() - lastSoundCheckTime > 20) {
    int soundLevel = analogRead(analogPin);
    lastSoundCheckTime = millis();
    
    // Always display the sound level for debugging
    Serial.println(soundLevel);
    
    // Check if the game is over and waiting for a clap to restart
    if (gameOver) {
      if (soundLevel > SOUND_THRESHOLD) {
        gameOver = false;
        userScore = 0;
        timeLimit = 2000;
        
        //pause before first command
        delay(1000);
        
        // first command of new game
        issueNewCommand();
      }
    }
    // check for clap if we're waiting for a response
    else if (waitingForResponse) {
      // Check if time limit has expired
      if (millis() - lastCommandTime > timeLimit) {
        // time up, user failed
        playFailSound();
        Serial.print("Final score: ");
        Serial.println(userScore);
        
        //game over state
        gameOver = true;
        waitingForResponse = false;
        
        // Turn off all LEDs
        turnOffAllLEDs();
        
        delay(1000);
      }
      
      // Check for clap
      if (soundLevel > SOUND_THRESHOLD) {
        // Clap detected!
        Serial.print("Clap detected Level: ");
        Serial.println(soundLevel);
        
        // Score a point
        userScore++;
        Serial.print("Correct Score: ");
        Serial.println(userScore);
        
        // Run the LED sequence as reward
        playLEDSequence();
        
        // Reduce time limit (but not below 500ms)
        timeLimit = max(500, timeLimit - 50);
        
        // Wait a bit before next command
        delay(1000);
        
        // Issue new command
        issueNewCommand();
      }
    }
  }
}

// Function to issue a new command
void issueNewCommand() {
  // Reset for new command
  waitingForResponse = false;
  turnOffAllLEDs();
  
  // Play the command sound
  playCommandSound();
  
  // Start timing
  lastCommandTime = millis();
  waitingForResponse = true;
  
  Serial.print("New command! Time limit: ");
  Serial.print(timeLimit);
  Serial.println("ms");
}

// Function to play the LED sequence
void playLEDSequence() {
  digitalWrite(ledPin1, HIGH);
  delay(100);
  digitalWrite(ledPin1, LOW);
  delay(100);
  
  digitalWrite(ledPin2, HIGH);
  delay(100);
  digitalWrite(ledPin2, LOW);
  delay(100);
  
  digitalWrite(ledPin3, HIGH);
  delay(100);
  digitalWrite(ledPin3, LOW);
  delay(100);
  
  digitalWrite(ledPin4, HIGH);
  delay(100);
  digitalWrite(ledPin4, LOW);
  delay(100);
}

// Function to turn off all LEDs
void turnOffAllLEDs() {
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, LOW);
}

// Function to play a clap command sound
void playCommandSound() {
  // Play a distinctive tone that means you should clap
  tone(buzzerPin, 880, 200); // A5 note for 200ms
  delay(200);
  noTone(buzzerPin);
  tone(buzzerPin, 1760, 200); // A6 note for 200ms
  delay(200);
  noTone(buzzerPin);
}

// Function to play a failure sound
void playFailSound() {
  // Descending tone
  tone(buzzerPin, 392, 200); // G4
  delay(200);
  noTone(buzzerPin);
  tone(buzzerPin, 311, 400); // Eb4
  delay(400);
  noTone(buzzerPin);
}

// Function to play startup sound
void playStartupSound() {
  tone(buzzerPin, 440, 200); // A4
  delay(200);
  noTone(buzzerPin);
  tone(buzzerPin, 587, 200); // D5
  delay(200);
  noTone(buzzerPin);
  tone(buzzerPin, 880, 400); // A5
  delay(400);
  noTone(buzzerPin);
}
