#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int button[] = {2, 3, 4, 5};
int currentButtonState[4];
int prevButtonState[4];

int numButtons = sizeof(button) / sizeof(button[0]);

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);

  for (int i = 0; i < numButtons; i++) {
    pinMode(button[i], INPUT_PULLUP);
    prevButtonState[i] = HIGH;
  }

  lcd.setCursor(0, 0);
  lcd.print("Hi Everybody");
  lcd.setCursor(0, 1);
  lcd.print("Button: ");
}

void loop() {
  for (int i = 0; i < numButtons; i++) {
    currentButtonState[i] = digitalRead(button[i]);

    if (currentButtonState[i] == LOW && prevButtonState[i] == HIGH) {
      Serial.print(i);
      Serial.println("_p");
      lcd.setCursor(7, 1);
      lcd.print("   ");
      lcd.setCursor(7, 1);
      lcd.print(i);
    }
    if (currentButtonState[i] == HIGH && prevButtonState[i] == LOW) {
      Serial.print(i);
      Serial.println("_r");
    }
    prevButtonState[i] = currentButtonState[i];
  }
}
