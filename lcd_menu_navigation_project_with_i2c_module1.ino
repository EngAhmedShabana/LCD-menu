#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(32,16,2);
byte arrow[8] = {
  B10000,
  B11000,
  B11100,
  B11110,
  B11111,
  B11110,
  B11100,
  B11000
};
byte counter=0;
#define pb1 2
#define pb2 3
void setup() {
  pinMode(pb1,INPUT_PULLUP);
  pinMode(pb2,INPUT_PULLUP);
  lcd.init();
  lcd.backlight();
  lcd.createChar(0,arrow);
  lcd.setCursor(0,0);
  lcd.write(0);
  lcd.setCursor(1,0);
  lcd.print("Select Program   ");
  lcd.setCursor(1,1);
  lcd.print("Settings   ");

}

void loop() {
  
  //UP
  if(!digitalRead(pb2)){
    while(!digitalRead(pb2));
    counter++;
    if(counter==1){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.write(0);
    lcd.setCursor(1,0);
  lcd.print("Settings   ");
  lcd.setCursor(1,1);
  lcd.print("Power Saving   ");
  }else if(counter==2){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.write(0);
    lcd.setCursor(1,0);
  lcd.print("Power Saving  ");
  lcd.setCursor(1,1);
  lcd.print("Shut Down  ");
  counter++;
  }else if(counter>=3){
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.write(0);
    lcd.setCursor(1,0);
  lcd.print("Power Saving   ");
  lcd.setCursor(1,1);
  lcd.print("Shut Down  ");
  }
  }
  //Down
  if(!digitalRead(pb1)){
    while(!digitalRead(pb1));
    counter--;
  if(counter<=1){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.write(0);
    lcd.setCursor(1,0);
  lcd.print("Select Program  ");
  lcd.setCursor(1,1);
  lcd.print("Settings  ");}
  else if(counter==2){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.write(0);
    lcd.setCursor(1,0);
  lcd.print("Settings  ");
  lcd.setCursor(1,1);
  lcd.print("Power Saving  ");
  }
 else if(counter==3){
  lcd.clear();
    lcd.setCursor(0,0);
    lcd.write(0);
    lcd.setCursor(1,0);
  lcd.print("Power Saving  ");
  lcd.setCursor(1,1);
  lcd.print("Shut Down  ");
  }
  }
}