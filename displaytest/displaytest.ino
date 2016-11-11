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
         lcd.print("AND 7408");
         break;
      case 2 :
         lcd.print("OR 7432");
         break;
      case 3 :
         lcd.print("XOR 7486");
         break;
      case 4 :
         lcd.print("NAND 7400");
         break;
      case 5 :
         lcd.print("NOR 7402");
         break;
      case 6 :
         lcd.print("XNOR 7466");
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

  
  bool compareArrays(int a[],int b[]) {
  int ii;
  for(ii = 1; ii <= 4; ii++) {
    if (a[ii] != b[ii]) 
    return false;
  }
  return true;
}
void andTest1(){

  int inp11=30;
  int inp12=31;
  int outp1=5;
  
  int inp21=32;
  int inp22=33;
  int outp2=4;
  
  int inp31=34;
  int inp32=35;
  int outp3=3;
  
  int inp41=36;
  int inp42=37;
  int outp4=2;
  
  int i;
  int andres[]={0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1};
  int orres[]={0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1};
  int xorres[]={0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0};
  int nandres[]={1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0};
  int norres[]={1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0};
  int xnorres[]={1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1};
  int outa1[4];
  int outa2[4];
  int outa3[4];
  int outa4[4];
  digitalWrite(inp11,LOW);
  digitalWrite(inp12,LOW);
  digitalWrite(outp1,LOW);

  digitalWrite(inp21,LOW);
  digitalWrite(inp22,LOW);
  digitalWrite(outp2,LOW);

  digitalWrite(inp31,LOW);
  digitalWrite(inp32,LOW);
  digitalWrite(outp3,LOW);

  digitalWrite(inp41,LOW);
  digitalWrite(inp42,LOW);
  digitalWrite(outp4,LOW);
  for(i=0;i<4;i++){
    if(i==0){
              pinMode(inp11, OUTPUT);           
              digitalWrite(inp11,LOW);
              pinMode(inp12, OUTPUT);           
              digitalWrite(inp12,LOW);
              pinMode(outp1, INPUT);
              outa1[i]=digitalRead(outp1);
          
              pinMode(inp21, OUTPUT);           
              digitalWrite(inp21,LOW);
              pinMode(inp22, OUTPUT);           
              digitalWrite(inp22,LOW);
              pinMode(outp2, INPUT);
              outa2[i]=digitalRead(outp2);
          
              pinMode(inp31, OUTPUT);           
              digitalWrite(inp31,LOW);
              pinMode(inp32, OUTPUT);           
              digitalWrite(inp32,LOW);
              pinMode(outp3, INPUT);
              outa3[i]=digitalRead(outp3);
          
              pinMode(inp41, OUTPUT);           
              digitalWrite(inp41,LOW);
              pinMode(inp42, OUTPUT);           
              digitalWrite(inp42,LOW);
              pinMode(outp4, INPUT);
              outa4[i]=digitalRead(outp4);
    }
    if(i==1){
              pinMode(inp11, OUTPUT);           
              digitalWrite(inp11,LOW);
              pinMode(inp12, OUTPUT);           
              digitalWrite(inp12,HIGH);
              pinMode(outp1, INPUT);
              outa1[i]=digitalRead(outp1);
          
               pinMode(inp21, OUTPUT);           
              digitalWrite(inp21,LOW);
              pinMode(inp22, OUTPUT);           
              digitalWrite(inp22,HIGH);
              pinMode(outp2, INPUT);
              outa2[i]=digitalRead(outp2);
          
               pinMode(inp31, OUTPUT);           
              digitalWrite(inp31,LOW);
              pinMode(inp32, OUTPUT);           
              digitalWrite(inp32,HIGH);
              pinMode(outp3, INPUT);
              outa3[i]=digitalRead(outp3);
          
               pinMode(inp41, OUTPUT);           
              digitalWrite(inp41,LOW);
              pinMode(inp42, OUTPUT);           
              digitalWrite(inp42,HIGH);
              pinMode(outp4, INPUT);
              outa4[i]=digitalRead(outp4);
    }
    if(i==2){
            pinMode(inp11, OUTPUT);           
            digitalWrite(inp11,HIGH);
            pinMode(inp12, OUTPUT);           
            digitalWrite(inp12,LOW);
            pinMode(outp1, INPUT);
            outa1[i]=digitalRead(outp1);
        
             pinMode(inp21, OUTPUT);           
            digitalWrite(inp21,HIGH);
            pinMode(inp22, OUTPUT);           
            digitalWrite(inp22,LOW);
            pinMode(outp2, INPUT);
            outa2[i]=digitalRead(outp2);
        
             pinMode(inp31, OUTPUT);           
            digitalWrite(inp31,HIGH);
            pinMode(inp32, OUTPUT);           
            digitalWrite(inp32,LOW);
            pinMode(outp3, INPUT);
            outa3[i]=digitalRead(outp3);
        
             pinMode(inp41, OUTPUT);           
            digitalWrite(inp41,HIGH);
            pinMode(inp42, OUTPUT);           
            digitalWrite(inp42,LOW);
            pinMode(outp4, INPUT);
            outa4[i]=digitalRead(outp4);
    }
    if(i==3){
            pinMode(inp11, OUTPUT);           
            digitalWrite(inp11,HIGH);
            pinMode(inp12, OUTPUT);           
            digitalWrite(inp12,HIGH);
            pinMode(outp1, INPUT);
            outa1[i]=digitalRead(outp1);
        
              pinMode(inp21, OUTPUT);           
            digitalWrite(inp21,HIGH);
            pinMode(inp22, OUTPUT);           
            digitalWrite(inp22,HIGH);
            pinMode(outp2, INPUT);
            outa2[i]=digitalRead(outp2);
        
              pinMode(inp31, OUTPUT);           
            digitalWrite(inp31,HIGH);
            pinMode(inp32, OUTPUT);           
            digitalWrite(inp32,HIGH);
            pinMode(outp3, INPUT);
            outa3[i]=digitalRead(outp3);
        
              pinMode(inp41, OUTPUT);           
            digitalWrite(inp41,HIGH);
            pinMode(inp42, OUTPUT);           
            digitalWrite(inp42,HIGH);
            pinMode(outp1, INPUT);
            outa4[i]=digitalRead(outp4);
    }
    }
    Serial.println(outa1[0]);
    Serial.println(outa1[1]);
    Serial.println(outa1[2]);
    Serial.println(outa1[3]);

     int outTotal[16];
    int j;
    for(j=0;j<16;j++){
      if(j<4){
        outTotal[j]=outa1[j];
        }
      else if(j<8){
        outTotal[j]=outa2[j-4];
        }
      else if(j<12){
        outTotal[j]=outa3[j-8];
        }
      else if(j<16){
        outTotal[j]=outa4[j-12];
        }

      }
 int k;
  int detect=0;
  for(k=0;k<16;k++){
    if(outTotal[k]!=andres[k]){
        break;
    }
    else if(k==15){
        detect=1;
    }
  }

  for(k=0;k<16;k++){
    if(outTotal[k]!=orres[k]){
        break;
    }
    else if(k==15){
        detect=2;
    }
  }

  for(k=0;k<16;k++){
    if(outTotal[k]!=xorres[k]){
        break;
    }
    else if(k==15){
        detect=3;
    }
  }

  for(k=0;k<16;k++){
    if(outTotal[k]!=nandres[k]){
        break;
    }
    else if(k==15){
        detect=4;
    }
  }

  for(k=0;k<16;k++){
    if(outTotal[k]!=norres[k]){
        break;
    }
    else if(k==15){
        detect=5;
    }
  }

  for(k=0;k<16;k++){
    if(outTotal[k]!=xnorres[k]){
        break;
    }
    else if(k==15){
        detect=6;
    }
  }

    if(! detect==0){
           p1=detect;
           p2=2;

    }
    else{
        p1=8;
        p2=8;
    }

  
}  
  

void setup()
{ pinMode(backLight, OUTPUT);
  digitalWrite(backLight, HIGH);
  Serial.begin(9600); //onTest
    
}

void loop()
{
dynamicinput();
andTest1();
 display(p1,p2);
 delay(1500);

}

