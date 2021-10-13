#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int *ElemType;
void CreatArray(ElemType *arr,int num);
void ArrayDisplay(ElemType arr,int num);
void Swap(ElemType a,ElemType b);
void MergeSort0(ElemType arr,int num);
void MSort0(ElemType previous,ElemType next,int start,int end,int num);
void MergeSort1(ElemType arr,int len);
//O(nlogn)

int main(void)
{
    ElemType arr;
    int num = 20;
    CreatArray(&arr,num);
    ArrayDisplay(arr,num);
    MergeSort1(arr,num);
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

void Merge0(ElemType disorder,ElemType orderly,int start,int mid,int end)
{
    int i,j,k,p;
    for(i=start-1,j=mid,k=start-1;i<mid&&j<end;k++){//映射到数组
        if(*(disorder+i) > *(disorder+j)){          //一直在一个已经额外申请的数组里排序
            *(orderly+k) = *(disorder+j);           //长度等于原来数组所以k=start-1
            j++;
        }else{
            *(orderly+k) = *(disorder+i);
            i++;
        }
    }
    for(p=i;p<mid;p++){
        *(orderly+k) = *(disorder+p);
        k++;
    }
    for(p=j;p<end;p++){
        *(orderly+k) = *(disorder+p);
        k++;
    }
}

//这个now每次都只使用一部分地方，可以每次申请end-start+1的大小不过会导致修改的地方比较多
//Merge里面还有 *(next+start-1) = *(previous+start-1);递归就很占用空间

void MSort0(ElemType previous,ElemType next,int start,int end,int num)
{
    int mid;
    if(start == end){
        *(next+start-1) = *(previous+start-1);//映射到数组
    } else{
        ElemType now = (ElemType)malloc(sizeof(int)*num);
        mid = (start+end)/2;
        MSort0(previous,now,start,mid,num);
        MSort0(previous,now,mid+1,end,num);
        Merge0(now,next,start,mid,end);
        free(now);
    }
}

void MergeSort0(ElemType arr,int num)
{
    int i;
    ElemType orderly = (ElemType)malloc(sizeof(int)*num);
    MSort0(arr,orderly,1,num,num);
    for(i=0;i<num;i++){   //原来的没有变化
        *(arr+i) = *(orderly+i);
    }
    free(orderly);
}

//分组归并
void GroupSort(ElemType disorder,ElemType orderly,int gap,int len)
{
    int i;
    for(i=1;i<=len-2*gap+1;i=i+2*gap){
        Merge0(disorder,orderly,i,i+gap-1,i+2*gap-1);
    }
    if(len-i+1 > gap){//剩下的大于半个分组
        Merge0(disorder,orderly,i,i+gap-1,len);
    } else{//小于半个//当正好i大于len排序在temp里完成进入GroupSort(temp,arr,i,len);
        for(;i<=len;i++){//复制到原数组
            *(orderly+i-1) = *(disorder+i-1);
        }
    }
}

//非递归也解决了上面递归没有在原来数组里排好
void MergeSort1(ElemType arr,int len)
{
    int i = 1;
    ElemType temp = (ElemType)malloc(sizeof(int)*len);
    while(i < len){
        GroupSort(arr,temp,i,len); //两个数组交替工作一个作为disorder
        i*=2;
        GroupSort(temp,arr,i,len);
        i*=2;
    }
    free(temp);
}