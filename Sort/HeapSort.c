#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int *ElemType;
void CreatArray(ElemType *arr,int num);
void ArrayDisplay(ElemType arr,int num);
void Swap(ElemType a,ElemType b);
void HeapSort(ElemType arr,int num);

//O(nlogn)  https://www.cnblogs.com/GHzcx/p/9635161.html

int main(void)
{
    ElemType arr;
    int num = 20;
    CreatArray(&arr,num);
    ArrayDisplay(arr,num);
    HeapSort(arr,num);
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
//S不能为0映射到数组要注意下
void HeapAdjust(ElemType arr,int num,int s)
{
    int i;
    int t = *(arr+s-1);
    for(i=2*s;i<=num;i*=2){
        if(i<num && *(arr+i-1)<*(arr+i)) i++;
        if(t > *(arr+i-1)) break;
        *(arr+s-1) = *(arr+i-1);
        s = i;
    }
    *(arr+s-1) = t;
}

void HeapSort(ElemType arr,int num)
{
    int i;
    for(i=num/2;i>=1;i--){ //每次调用只能调整一条线路
        HeapAdjust(arr,num,i);
    }
    for(i=num;i>1;i--){
        Swap(arr,arr+i-1);//对应到数组
        HeapAdjust(arr,i-1,1);//只需要调整一条线路
    }
}