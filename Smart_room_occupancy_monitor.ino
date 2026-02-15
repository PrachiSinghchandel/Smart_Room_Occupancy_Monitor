#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);

#define in 8
#define out 9
#define Fan 10
int count=0;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Smart Room Occupancy Monitor");
  delay(2000);
  pinMode(in, INPUT);
  pinMode(out, INPUT);
  pinMode(Fan, OUTPUT);
  lcd.clear();
  lcd.print("Number of people in the room: ");
  lcd.setCursor(0, 1);
  lcd.print(count);

}

void loop() {
  int in_value = digitalRead(in);
  int out_value = digitalRead(out);
  if(in_value==LOW) {
    count++;
    lcd.clear();
    lcd.print("Number of people in the room: ");
    lcd.setCursor(0, 1);
    lcd.print(count);
    delay(1000);
  }
  if(out_value==LOW) {
    count--;
    lcd.clear();
    lcd.print("Number of people in the room: ");
    lcd.setCursor(0, 1);
    lcd.print(count);
    delay(1000);
  }
  if(count==0) {
    lcd.clear();
    lcd.print("Number of people in the room: ");
    lcd.setCursor(0, 1);
    lcd.print(count);
    digitalWrite(Fan, LOW);
    delay(200);
  }
}