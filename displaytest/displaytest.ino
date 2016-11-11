#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 9, 8, 7, 6);
int backLight = 13;
int p1=0;
int p2=0;
    

void display(int a,int b){
  // turn backlight on. Replace 'HIGH' with 'LOW' to turn it off.
  lcd.begin(16,2);              // columns, rows.  use 16,2 for a 16x2 LCD, etc.
  lcd.clear();                  // start with a blank screen
  lcd.setCursor(0,0);// set cursor to column 0, row 0 (the first row)
  switch(a) {
      case 1 :
         lcd.print("NOT 7404");
         break;
      case 2 :
         lcd.print("AND 7408");
         break;
      case 3 :
         lcd.print("NAND 7400");
         break;
      case 4 :
         lcd.print("OR 7432");
         break;
      case 5 :
         lcd.print("XOR 7486");
         break;
      case 6 :
         lcd.print("NOR 7402");
         break; 
      default :
         lcd.print("ERROR");
         }
  lcd.setCursor(0,1);           // set cursor to column 0, row 1
  if(b==2){
    lcd.print("OK");
    }
  else{
    lcd.print("ERROR");
    }
  }
void dynamicinput(){


  int num[2];
  int digitc=0;

 if (Serial.available()) {
    int value = Serial.parseInt();
    while (value > 0) {
    num[digitc] = value % 10;
    value /= 10;
    digitc++;
    
}
    Serial.print(num[1]);
    Serial.println(num[0]);
     display(num[1],num[0]);
    }


  
  }
void andTest(){
  int inp1=30;
  int inp2=31;
  int outp1=4;
  int i;
  int res[]={0,0,0,1};
  int outa[4];
  digitalWrite(inp1,LOW);
  digitalWrite(inp2,LOW);
  digitalWrite(outp1,LOW);
  for(i=0;i<4;i++){
    if(i==0){
    pinMode(inp1, OUTPUT);           
    digitalWrite(inp1,LOW);
    pinMode(inp2, OUTPUT);           
    digitalWrite(inp2,LOW);
    pinMode(outp1, INPUT);
    outa[i]=digitalRead(outp1);
    }
    if(i==1){
    pinMode(inp1, OUTPUT);           
    digitalWrite(inp1,LOW);
    pinMode(inp2, OUTPUT);           
    digitalWrite(inp2,HIGH);
    pinMode(outp1, INPUT);
    outa[i]=digitalRead(outp1);
    }
    if(i==2){
    pinMode(inp1, OUTPUT);           
    digitalWrite(inp1,HIGH);
    pinMode(inp2, OUTPUT);           
    digitalWrite(inp2,LOW);
    pinMode(outp1, INPUT);
    outa[i]=digitalRead(outp1);
    }
    if(i==3){
    pinMode(inp1, OUTPUT);           
    digitalWrite(inp1,HIGH);
    pinMode(inp2, OUTPUT);           
    digitalWrite(inp2,HIGH);
    pinMode(outp1, INPUT);
    outa[i]=digitalRead(outp1);
    }
    }
    Serial.println(outa[0]);
    Serial.println(outa[1]);
    Serial.println(outa[2]);
    Serial.println(outa[3]);
  }  
  

void setup()
{ pinMode(backLight, OUTPUT);
  digitalWrite(backLight, HIGH);
  Serial.begin(9600); //onTest
    
}

void loop()
{
dynamicinput();
andTest();
}

