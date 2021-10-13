#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>

typedef int *ElemType;
void CreatArray(ElemType *arr,int num);
void ArrayDisplay(ElemType arr,int num);
void Swap(ElemType a,ElemType b);
void ShellSort(ElemType arr,int num);

int main(void)
{
    ElemType arr;
    int num = 20;
    CreatArray(&arr,num);
    ArrayDisplay(arr,num);
    ShellSort(arr,num);
    ArrayDisplay(arr,num);
    return 0;
}


void CreatArray(ElemType *arr,int num)
{
    int i;
    if(num <= 0) exit(1);
    *arr = (int *)malloc(sizeof(int)*num);
    if(*arr == NULL) exit(1);
    srand(time(0));
    for(i=0;i<num;i++){
        *(*arr+i) = rand()%1000+1;
    }
}

void ArrayDisplay(ElemType arr,int num)
{
    int i;
    for(i=0;i<num;i++){
        printf("%d ",*(arr+i));
    }
    printf("\n");
}

void Swap(ElemType a,ElemType b)
{
    int t;
    t = *b;
    *b = *a;
    *a = t;
}

void ShellSort(ElemType arr,int num)
{
    int i,j,increment,k,p;
    p = log(num)/log(2);//换底公式
    do{
        increment=pow(2,p--)-1;
        for(i=0;i<increment;i++){
            for(j=i+increment;j<num;j+=increment){
                for(k=j;k>i;k-=increment){
                    if(*(arr+k)<*(arr+k-increment))
                        Swap(arr+k,arr+k-increment);
                    else break;
                }
            } 
        }
    }while(increment > 1);
}
