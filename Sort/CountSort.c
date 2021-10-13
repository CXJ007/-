#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef int *ElemType;
void CreatArray(ElemType *arr,int num);
void ArrayDisplay(ElemType arr,int num);
void Swap(ElemType a,ElemType b);
void Count0(ElemType arr,int num);
void Count1(ElemType arr,int num);

//O(n+k)
//速度挺快牺牲了空间啊 
int main(void)
{
    ElemType arr;
    int num = 20;
    CreatArray(&arr,num);
    ArrayDisplay(arr,num);
    Count1(arr,num);
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
        *(*arr+i) = rand()%100+1;
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

//不稳定
void Count0(ElemType arr ,int num)
{
    int max = 0;
    int min = 1000;
    int i,j=0;
    ElemType count = NULL;
    for(i=0;i<num;i++){
        if(max < *(arr+i)) max = *(arr+i);
        if(min > *(arr+i)) min = *(arr+i);
    }
    count = (ElemType)malloc(sizeof(int)*(max-min)+1);
    memset(count,0,(max-min)+1);
    for(i=0;i<num;i++){
        (*(count+*(arr+i)-min))++;
    }
    for(i=0;i<max-min+1;i++){
        while(*(count+i) != 0){
            (*(count+i))--;
            *(arr+j) = min+i;
            j++;
        }
    }
    free(count);
}

//用这个Count1或着把count数组变成队列；
void Count1(ElemType arr ,int num)
{
    int max = 0;
    int min = 1000;
    int i,j=0;
    ElemType count = NULL;
    ElemType temp = NULL;
    temp = (ElemType)malloc(sizeof(int)*num);
    for(i=0;i<num;i++){
        if(max < *(arr+i)) max = *(arr+i);
        if(min > *(arr+i)) min = *(arr+i);
    }
    count = (ElemType)malloc(sizeof(int)*(max-min)+1);
    memset(count,0,(max-min)+1);
    for(i=0;i<num;i++){
        (*(count+*(arr+i)-min))++;
    }
    for(i=1;i<max-min+1;i++) count[i]+=count[i-1]; //经过处理
    for(i=num-1;i>=0;i--){//逆序遍历。到着退出来 
		temp[count[arr[i]-min]-1]=arr[i];
		count[arr[i]-min]--;
    }
    for(int i=0;i<num;i++) arr[i]=temp[i];
    free(count);
    free(temp);
}

