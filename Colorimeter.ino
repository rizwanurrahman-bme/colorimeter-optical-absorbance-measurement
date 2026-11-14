#include <LiquidCrystal.h>
#include <math.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

float I0 = 974.0;

void setup() {
  pinMode(9, OUTPUT);

  lcd.begin(16, 2);
  lcd.print("Colorimeter");
  delay(2000);
  lcd.clear();
}

void loop() {
  digitalWrite(9, HIGH);

  int I = analogRead(A0);

  float absorbance = log10(I0 / (float)I);

  lcd.setCursor(0, 0);
  lcd.print("Light: ");
  lcd.print(I);
  lcd.print("   ");

  lcd.setCursor(0, 1);
  lcd.print("Abs: ");
  lcd.print(absorbance, 3);
  lcd.print("    ");

  delay(500);
}