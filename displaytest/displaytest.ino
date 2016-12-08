#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 9, 8, 7, 6); //Lcd Pins
int backLight = 13; 
	int p1=0; // print line 1 and 2 
	int p2=0;
	int detect=0; //detector ic sequence number
	


void display(int a,int b){
  // turn backlight on. Replace 'HIGH' with 'LOW' to turn it off.
  lcd.begin(16,2);              // columns, rows.  use 16,2 for a 16x2 LCD, etc.
  lcd.clear();                  // start with a blank screen
  lcd.setCursor(0,0);// set cursor to column 0, row 0 (the first row)
  switch(a) {						//display ic Identity
      
      case 1 :
         lcd.print("AND 7408");
         break;
    case 2 :
         lcd.print("OR 7432");
         break;
      case  3 :
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
    case 7:
      lcd.print("NO IC");
      break;
   
   case 8:
      lcd.print("NOT 7404");
      break;
      default :
		 lcd.print("");
        // lcd.print("Unable To Detect ");
         }
  lcd.setCursor(0,1);           // set cursor to column 0, row 1
  if(b==2){
    //lcd.print("OK");
    lcd.print("");
    }
  else{
    //lcd.print("ERROR");
    //lcd.print("ERROR");
    lcd.print("");
    }
  }
/*void dynamicinput(){ // Debuging through serial


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
*/

  
  /*bool compareArrays(int a[],int b[]) {  //2 array compare
  int ii;
  for(ii = 1; ii <= 4; ii++) {
    if (a[ii] != b[ii]) 
    return false;
  }
  return true;
}
*/

//NOT
void notTest(){

//Input  output initializer
  int inp1=31; //1
  int outp1=30; //2
 
  int inp2=5; //3
  int outp2=33; //4

  
  int inp3=32;//5
  int outp3=4;//6

  int inp4=36;//9
  int outp4=2;//8

  int outp5=37; //10
  int inp5=3; //11
  
  int inp6=32;//13
  int outp6=35;//12
  
  int i;
  
  int notres[]={1,1,1,1,1,1,0,0,0,0,0,0};
  
  int outa[12];	//6x2 gates in 1 ic
  

 // intializing all as low
  digitalWrite(inp1,LOW);
  digitalWrite(inp2,LOW);
  digitalWrite(inp3,LOW);
  digitalWrite(inp4,LOW);
  digitalWrite(inp5,LOW);
  digitalWrite(inp6,LOW);

  digitalWrite(outp1,LOW);
  digitalWrite(outp2,LOW);
  digitalWrite(outp3,LOW);
  digitalWrite(outp4,LOW);
  digitalWrite(outp5,LOW);
  digitalWrite(outp6,LOW);

  pinMode(outp1, INPUT); 
  pinMode(outp2, INPUT); 
  pinMode(outp3, INPUT); 
  pinMode(outp4, INPUT); 
  pinMode(outp5, INPUT); 
  pinMode(outp6, INPUT); 



			//Readind data for 0 input
              pinMode(inp1, OUTPUT);           
            digitalWrite(inp1,LOW);
            outa[0]=digitalRead(outp1);
			
              pinMode(inp2, OUTPUT);           
            digitalWrite(inp2,LOW);
            outa[1]=digitalRead(outp2);
			
			  pinMode(inp3, OUTPUT);           
            digitalWrite(inp3,LOW);
            outa[2]=digitalRead(outp1);

			  pinMode(inp4, OUTPUT);           
            digitalWrite(inp4,LOW);
            outa[3]=digitalRead(outp4);
			
              pinMode(inp5, OUTPUT);           
            digitalWrite(inp5,LOW);
            outa[4]=digitalRead(outp5);
			
			  pinMode(inp6, OUTPUT);           
            digitalWrite(inp6,LOW);
            outa[5]=digitalRead(outp6);

			 // intializing all as low
  digitalWrite(inp1,LOW);
  digitalWrite(inp2,LOW);
  digitalWrite(inp3,LOW);
  digitalWrite(inp4,LOW);
  digitalWrite(inp5,LOW);
  digitalWrite(inp6,LOW);

  digitalWrite(outp1,LOW);
  digitalWrite(outp2,LOW);
  digitalWrite(outp3,LOW);
  digitalWrite(outp4,LOW);
  digitalWrite(outp5,LOW);
  digitalWrite(outp6,LOW);

				//Readind data for 1 HIGH
              pinMode(inp1, OUTPUT);           
            digitalWrite(inp1,HIGH);
            outa[6]=digitalRead(outp1);
			
              pinMode(inp2, OUTPUT);           
            digitalWrite(inp2,HIGH);
            outa[7]=digitalRead(outp2);
			
			  pinMode(inp3, OUTPUT);           
            digitalWrite(inp3,HIGH);
            outa[8]=digitalRead(outp1);

			  pinMode(inp4, OUTPUT);           
            digitalWrite(inp4,HIGH);
            outa[9]=digitalRead(outp4);
			
              pinMode(inp5, OUTPUT);           
            digitalWrite(inp5,HIGH);
            outa[10]=digitalRead(outp5);
			
			  pinMode(inp6, OUTPUT);           
            digitalWrite(inp6,HIGH);
            outa[11]=digitalRead(outp6);
			  
		
 int k;
  for(k=0;k<12;k++){
    if(outa[k]!=notres[k]){
        break;
    }
    else if(k==11){
        detect=8;
    }
  }

   if(!detect==0){
           p1=detect;
           p2=2;

    }
    else{
        p1=9;
        p2=9;
    }
 display(p1,p2);


}






//NOR
void norTest(){

//Input  output initializer
  int inp11=30; //2
  int inp12=5; //3
  int outp1=31; //1
  
  int inp21=32; //5
  int inp22=4; //6
  int outp2=33; //4

  
  int inp32=35;//12
  int inp31=3;//11
  int outp3=34;//13

  int inp41=36;//9
  int inp42=2;//8
  int outp4=37;//10
  
  int i;

  int norres[]={1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0};
  
  int outa1[4];	//4 gates in 1 ic
  int outa2[4];
  int outa3[4];
  int outa4[4];

 // intializing all as low
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

  for(i=0;i<4;i++){ //takeing data from all gates
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

     int outTotal[16]; //combining all gates data
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
  



  for(k=0;k<16;k++){
    if(outTotal[k]!=norres[k]){
        break;
    }
    else if(k==15){
        detect=5;
    }
  }
  
	notTest();


}

//Nand XOR AND OR
void andTest1(){ 


  //Input  output initializer
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
  int noic[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  int andres[]={0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1};
  int orres[]={0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1};
  int xorres[]={0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0};
  int nandres[]={1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0};
  //int norres[]={1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0};  not working
  //int xnorres[]={1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1}; delete
  int outa1[4];	//4 gates in 1 ic
  int outa2[4];
  int outa3[4];
  int outa4[4];

 // intializing all as low
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

  for(i=0;i<4;i++){ //takeing data from all gates
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

     int outTotal[16]; //combining all gates data
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
  
	
   for (k = 0;k<16;k++) {
    if (outTotal[k] != noic[k]) {
      break;
    }
    else if (k == 15) {
      detect = 7;
    }
  }
 

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
  
 norTest();

 /* for(k=0;k<16;k++){ //nor not working 
    if(outTotal[k]!=norres[k]){
        break;
    }
    else if(k==15){
        detect=5;
    }
  }
*/
/*  for(k=0;k<16;k++){ //not working xnor
    if(outTotal[k]!=xnorres[k]){
        break;
    }
    else if(k==15){
        detect=6;
    }
	}
*/
  

  

	/*    if(!detect==0){
           p1=detect;
           p2=2;

    }
    else{
        p1=8;
        p2=8;
    }
 display(p1,p2);
*/
  
}  
  

void setup()
{ pinMode(backLight, OUTPUT);
  digitalWrite(backLight, HIGH);
 // Serial.begin(9600); //onTest

}

void loop()
{	
  
  andTest1();

 

delay(500);
}



