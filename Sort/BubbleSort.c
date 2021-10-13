#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int *ElemType;
void CreatArray(ElemType *arr,int num);
void ArrayDisplay(ElemType arr,int num);
void Swap(ElemType a,ElemType b);
void Bubble0(ElemType arr,int num);
void Bubble1(ElemType arr,int num);

//O(n^2)

int main(void)
{
    ElemType arr;
    int num = 20;
    CreatArray(&arr,num);
    ArrayDisplay(arr,num);
    Bubble1(arr,num);
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

//让目标通过不断比较冒到最后
void Bubble0(ElemType arr,int num)
{
    int i,j;
    for(i=0;i<num-1;i++){ //剩下一个必然已经排序完成
        for(j=0;j<num-i-1;j++){     //-1因为*(arr+j+1)往后一位比较了
            if(*(arr+j) > *(arr+j+1)) Swap(arr+j,arr+j+1);
        }
    }
}

void Bubble1(ElemType arr,int num)
{
    int i,j,flag;
    flag = 1;
    for(i=0;i<num-1;i++){
        for(j=0;j<num-i-1;j++){
            if(*(arr+j) > *(arr+j+1)){
                Swap(arr+j,arr+j+1);
                flag = 1;
            }else flag = 0;
        }
        if(flag == 0) break;
    }
}
