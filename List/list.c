#include <stdio.h>
#include "list.h"

Status ListInsert(list *l,int place,ElemType e);
Status ListRead(list *l,int place,ElemType *e);
Status ListDisplay(list *l);
Status ListDelet(list *l,int place,ElemType *e);

int main(void)
{
    int i;
    list *testlist = NULL;
    testlist = (list *)malloc(sizeof(list));
    if(testlist == NULL) printf("init_err\n");
    testlist->length = 0;
    ListInsert(testlist,1,1);
    ListInsert(testlist,1,2);
    ListInsert(testlist,2,3);
    ListInsert(testlist,1,4);
    ListDisplay(testlist);
    ElemType data;
    ListDelet(testlist,3,&data);
    printf("%d\n",data);
    ListDisplay(testlist);
    return 0;
}

//place 1~MAXSIZE
//length 0~MAXSIZE
//多数在place前一位插入
Status ListInsert(list *l,int place,ElemType e)
{
    int i = 0;
    if(l == NULL) return ERR;
    if(l->length >= MAXSIZE) return ERR;
    if(place<1 || place>l->length+1) return ERR; //length+1开始为0没办法插入，所以肯在place插入
    if(place <= l->length){
        for(i=l->length-1;i>=place-1;i--){
            l->data[i+1] = l->data[i];
        }
    }
    l->data[place-1] = e;
    l->length++;
    return OK;
}

Status ListRead(list *l,int place,ElemType *e)
{
    if(l == NULL) return ERR;
    if(place > l->length) return ERR;
    *e = l->data[place-1];
    return OK;
}

Status ListDisplay(list *l)
{
    int i;
    if(l == NULL) return ERR;
    if(l->length == 0) return ERR;
    for(i=0;i<l->length;i++){
         printf(" %d",l->data[i]);
    }
    printf("\n");
    return OK;
}

Status ListDelet(list *l,int place,ElemType *e)
{
    int i;
    if(l == NULL) return ERR;
    if(l->length == 0) return ERR;
    if(place>l->length || place <1) return ERR;
    *e = l->data[place-1];
    for(i=place;i<l->length;i++){
        l->data[i-1] = l->data[i];
    }
    l->length--;
    return OK;
}
