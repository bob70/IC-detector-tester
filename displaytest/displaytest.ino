#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7, 6);
int backLight = 13;
void display(){
  pinMode(backLight, OUTPUT);
  digitalWrite(backLight, HIGH); 
  lcd.begin(16,2);            
  lcd.clear();             
  lcd.setCursor(0,0);          
  lcd.print("KOTHA");
  //lcd.setCursor(0,1);          
  //lcd.print("B"); 
  }





void setup()
{
  display();
}

void loop()
{
} 
