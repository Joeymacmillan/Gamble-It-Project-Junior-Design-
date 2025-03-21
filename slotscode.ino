#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define BUTTON_PIN 2

char symbols[] = {'$', '#', '@'};
char slots[3] = {' ', ' ', ' '};
bool spinning = false;

void setup() {
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.clearDisplay();
    randomSeed(analogRead(0));

    showStartMenu();
}

void loop() {
    if (!spinning) {
        if (digitalRead(BUTTON_PIN) == LOW) {
            delay(100);  // Debounce
            while (digitalRead(BUTTON_PIN) == LOW);  // Wait for button release
            spinning = true;
            spinSlots();
        }
    }
}

void showStartMenu() {
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(20, 20);
    display.print("Press to");
    display.setCursor(30, 40);
    display.print("Start");
    display.display();
}

void spinSlots() {
    int spinTime = 2000; // Total spin duration in milliseconds
    int delayTime = 50;  // Initial speed

    unsigned long startTime = millis();
    while (millis() - startTime < spinTime) {
        for (int i = 0; i < 3; i++) {
            slots[i] = symbols[random(0, 3)];
        }
        drawSlots();
        delay(delayTime);
        
        if (delayTime < 500) { // Gradually slow down
            delayTime += 20;
        }
    }

    // Set final result
    for (int i = 0; i < 3; i++) {
        slots[i] = symbols[random(0, 3)];
    }
    drawSlots();
    checkWin();
    spinning = false;
}

void drawSlots() {
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(30, 20);
    for (int i = 0; i < 3; i++) {
        display.print(slots[i]);
        display.print("  ");
    }
    display.display();
}

void checkWin() {
    if (slots[0] == '$' && slots[1] == '$' && slots[2] == '$') {
        display.setCursor(30, 40);
        display.print("YOU WIN!");
        display.display();
    }
}
