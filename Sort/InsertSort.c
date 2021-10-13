#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int *ElemType;
void CreatArray(ElemType *arr,int num);
void ArrayDisplay(ElemType arr,int num);
void Swap(ElemType a,ElemType b);
void InsertSort0(ElemType arr,int num);
void InsertSort1(ElemType arr,int num);
void InsertSort2(ElemType arr,int num);

//O(n^2)

int main(void)
{
    ElemType arr;
    int num = 20;
    CreatArray(&arr,num);
    ArrayDisplay(arr,num);
    InsertSort2(arr,num);
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

//在无序的数据里的第一个插入到有序数据里
void InsertSort0(ElemType arr,int num)
{
    int i,j,k;
    for(i=1;i<num;i++){
        k = *(arr+i);
        for(j=i;j>0;j--){
            if(k < *(arr+j-1)){
                *(arr+j) = *(arr+j-1);
            }else break;
        }
        *(arr+j) = k;
    }
}

//通过不断的交换直接到达目标位置不需要中间变量K
void InsertSort1(ElemType arr,int num)
{
    int i,j;
    for(i=1;i<num;i++){
        for(j=i;j>0;j--){
            if(*(arr+j) < *(arr+j-1)){
                Swap(arr+j,arr+j-1);
            }else break;
        }
    }
}

//通二分法找到插入的位置
void InsertSort2(ElemType arr,int num)
{
    int i,j,k,p,q,mid;
    
    for(i=1;i<num;i++){
        k = *(arr+i);
        p = 0;
        q = i-1;
        while(p <= q){
            mid = (p+q)/2;
            if(*(arr+mid) > k) q = mid-1;
            else if(*(arr+mid) < k) p = mid+1;
            else p = mid+1;
        }
        for(j=i;j>p;j--){ //选这个p因为在上面最后else是相等的条件保证相同时不交换，稳定的排序
            *(arr+j) = *(arr+j-1);//要用q就要把最后else改为q = mid-1  for(j=i;j>q+1;j--)
        }
        *(arr+j) = k;
    }
}


