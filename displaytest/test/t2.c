
#include<stdio.h>

int main(){
  int andres[]={0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1};
  int orres[]={0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1};
  int xorres[]={0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0};
  int nandres[]={1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0};
  int norres[]={1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0};
  int xnorres[]={1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1};
  int outTotal[]={0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,1};

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
            printf("GATE %d",detect);

    }
    else{
        printf("ERROR");
    }
return 0;
}

