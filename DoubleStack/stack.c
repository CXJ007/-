#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Status StackPush(Stack *s,ElemType e,int chose);
Status StackPop(Stack *s,ElemType *e,int chose);

int main(void)
{
    Stack *DoubleStack = (Stack *)malloc(sizeof(Stack));
    if(DoubleStack == NULL) printf("init_err\n");
    DoubleStack->top1 = -1;
    DoubleStack->top2 = MAXSIZE;
    int i = 60;
    while(i){
        StackPush(DoubleStack,61-i,i%2+1);
        i--;
    }
    for(i=0;i<MAXSIZE;i++){
        printf("%d ",DoubleStack->data[i]);
    }
    printf("\n");
    printf("TOP1=%d   TOP2=%d\n",DoubleStack->top1,DoubleStack->top2);
    i = 50;
    ElemType data;
    while(i){
        StackPop(DoubleStack,&data,i%2+1);
        i--;
        printf("%d ",data);
    }
    printf("\n");
    printf("TOP1=%d   TOP2=%d\n",DoubleStack->top1,DoubleStack->top2);
    return 0;
}

Status StackPush(Stack *s,ElemType e,int chose)
{
    if(s == NULL) return ERR;
    if(s->top1<-1 || s->top2>MAXSIZE) return ERR;
    if(s->top1+1 == s->top2) return ERR;
    if(chose == 1){
        s->top1++;
        s->data[s->top1] = e;
        return OK;
    }else if(chose == 2){
        s->top2--;
        s->data[s->top2] = e;
        return OK;
    }else return ERR;
}

Status StackPop(Stack *s,ElemType *e,int chose)
{
    if(s == NULL) return ERR;
    if(s->top1<=-1 && s->top2>=MAXSIZE) return ERR;
    if(chose == 1){
        *e = s->data[s->top1];
        s->top1--;
        return OK;
    }else if(chose == 2){
        *e = s->data[s->top2];
        s->top2++;
        return OK;
    }
    return ERR;
}