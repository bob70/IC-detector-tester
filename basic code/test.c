#include<stdio.h>
#include <string.h>

int outputArray[4];
int inputArray[2][4];

void input()
{
    int inputArray[2][4] = {
        {0, 0, 1, 1},
        {0, 1, 0, 1}
    };
}

void output(int arr[4])
{
    int i;

    for(i=0;i<=strlen(arr);i++)
    {
        outputArray[i]=arr[i];
    }

    int not[1] = {1,0};
    int and[3]={0,0,0,1};
    int or[3]={0,1,1,1};
    int xor[3]={0,1,1,0};
    int nand[3]={1,1,1,0};
    int nor[3]={1,0,0,0};

    if(outputArray[0]==not[0] && outputArray[1]==not[1] && outputArray[2]==not[2] && outputArray[3]==not[3])
    {
        printf("AND gate");
    }
    else if(outputArray[0]==or[0] && outputArray[1]==or[1] && outputArray[2]==or[2] && outputArray[3]==or[3])
    {
        printf("OR gate");
    }
    else if(outputArray[0]==xor[0] && outputArray[1]==xor[1] && outputArray[2]==xor[2] && outputArray[3]==xor[3])
    {
        printf("XOR gate");
    }
    else if(outputArray[0]==nand[0] && outputArray[1]==nand[1] && outputArray[2]==nand[2] && outputArray[3]==nand[3])
    {
        printf("NAND gate");
    }
    else if(outputArray[0]==nor[0] && outputArray[1]==nor[1] && outputArray[2]==nor[2] && outputArray[3]==nor[3])
    {
        printf("NOR gate");
    }
    else if(outputArray[0]==not[0] && outputArray[1]==not[1])
    {
        printf("NOT gate");
    }
    else
    {
        printf("GATE error.");
    }
}

int main()
{
    int arr[4] = {1,0 ,0,1};
    output(arr);
}
