#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Status LinkStackPush(LinkStack *L,ElemType e);
Status LinkStackPop(LinkStack *L,ElemType *e);

int main(void)
{
    LinkStack *L = (LinkStack *)malloc(sizeof(LinkStack));
    if(L == NULL) printf("init_err\n");
    L->count = 0;
    printf("ok\n");
    LinkStackPush(L,1);
    LinkStackPush(L,2);
    LinkStackPush(L,3);
    printf("%d  %d  %d\n",L->top->data,L->top->next->data,L->top->next->next->data);
    printf("%d\n",L->count);
    ElemType data;
    LinkStackPop(L,&data);
    printf("%d\n",data);
    printf("%d\n",L->count);
    return 0;
}

Status LinkStackPush(LinkStack *L,ElemType e)
{
    Node *p = NULL;
    if(L == NULL) return ERR;
    p = (Node *)malloc(sizeof(Node));
    if(p == NULL) return ERR;
    p->data = e;
    p->next = L->top;
    L->top = p;
    L->count++;
    return OK;
}

Status LinkStackPop(LinkStack *L,ElemType *e)
{
    Node *p;
    if(L == NULL) return ERR;
    if(L->count == 0)return ERR;
    p = L->top;
    *e = p->data;
    L->top = p->next;
    L->count--;
    free(p);
    return OK;
}