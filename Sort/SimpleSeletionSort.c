#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int *ElemType;
void CreatArray(ElemType *arr,int num);
void ArrayDisplay(ElemType arr,int num);
void Swap(ElemType a,ElemType b);
void SeletionSort(ElemType arr,int num);
//O(n^2)

int main(int argc,char *argv[])
{
    ElemType arr;
    int num = 10;
    CreatArray(&arr,num);
    ArrayDisplay(arr,num);
    SeletionSort(arr,num);
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

//不断的与未排好的元素比较找到更小或更大的然后交换比Bubble好在没有大量元素移动
void SeletionSort(ElemType arr,int num)
{
    int i,j,k;
    for(i=0;i<num-1;i++){   //num-1因为i只需要到倒数第二个然后由j=i+1
        k = i;
        for(j=i+1;j<num;j++){
            if(*(arr+k) > *(arr+j)) k = j;//find min
        }
        if(k != j) Swap(arr+k,arr+i);
    }
}

