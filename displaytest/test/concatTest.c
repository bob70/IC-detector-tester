#include<stdio.h>

int main(){

  int outa1[]={0,0,0,1};
  int outa2[]={0,1,1,1};
  int outa3[]={0,1,1,0};
  int outa4[]={1,1,1,0};

     int outTotal[16];
    int j,i;
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

    for(i=0;i<16;i++){
        printf("%d",outTotal[i]);
         printf("\n");
    }


return 0;
}
