#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define BUTTON_PIN 2

char symbols[] = {'$', '#', '@', '%', '&'};
char slots[3] = {' ', ' ', ' '};
bool spinning = true;

void setup() {
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.clearDisplay();
    randomSeed(analogRead(0));
}

void loop() {
    if (spinning) {
        for (int i = 0; i < 3; i++) {
            slots[i] = symbols[random(0, 5)];
        }
        drawSlots();
        delay(200);
    }
    
    if (digitalRead(BUTTON_PIN) == LOW) {
        delay(100); // Debounce
        spinning = false;
        checkWin();
        while (digitalRead(BUTTON_PIN) == LOW); // Wait for button release
    }
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
        display.print("WIN!");
        display.display();
    }
}
