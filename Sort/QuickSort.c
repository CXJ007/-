#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int *ElemType;
void CreatArray(ElemType *arr,int num);
void ArrayDisplay(ElemType arr,int num);
void Swap(ElemType a,ElemType b);
void QuickSort(ElemType arr,int num);

//O(logn)

int main(void)
{
    ElemType arr;
    int num = 20;
    CreatArray(&arr,num);
    ArrayDisplay(arr,num);
    QuickSort(arr,num);
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

int Partition(ElemType arr,int low,int hight)
{
    low--;
    hight--;
    int pivot = *(arr+low);
    while(low < hight){
        // while((pivot<=*(arr+hight)) && (low<hight)) hight--;
        // Swap(arr+low,arr+hight);
        // while((pivot>=*(arr+low)) && (low<hight)) low++;
        // Swap(arr+low,arr+hight);
        while((low<hight) && (pivot<=*(arr+hight))) hight--;
        Swap(arr+low,arr+hight);
        while((low<hight) && (pivot>=*(arr+low))) low++;
        Swap(arr+low,arr+hight);

    }  
    return ++low;
}

void QSort(ElemType arr,int low,int hight)
{
    int pivot;
    if(low < hight){
        pivot = Partition(arr,low,hight);
        QSort(arr,low,pivot-1);
        QSort(arr,pivot+1,hight);
    }
}

void QuickSort(ElemType arr,int num)
{
    QSort(arr,1,num);
}