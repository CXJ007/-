#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Status QueueInit(Queue **Q);
Status QueueEnter(Queue *Q,ElemType e);
Status QueueExit(Queue *Q,ElemType *e);

int main(void)
{
    int i;
    ElemType data;
    Queue *LinkQueue = NULL;
    QueueInit(&LinkQueue);
    for(i=0;i<10;i++){
        QueueEnter(LinkQueue,i);
    }
    for(i=0;i<13;i++){
        if(QueueExit(LinkQueue,&data) == OK) printf("%d ",data);
        else printf("null\n");
    }
    return 0;
}

Status QueueInit(Queue **Q)
{
    Node *p = NULL;
    if(*Q != NULL) return ERR;
    *Q = (Queue *)malloc(sizeof(Queue));
    if(*Q == NULL) return ERR;
    p = (Node *)malloc(sizeof(Node));
    if(p == NULL) return ERR;
    p->next = NULL;
    (*Q)->front = p;
    (*Q)->rear = p;
    return OK;
}

Status QueueEnter(Queue *Q,ElemType e)
{
    Node *p = NULL,*q;
    if(Q == NULL) return ERR;
    p = (Node *)malloc(sizeof(Node));
    if(p == NULL) return ERR;
    p->next = NULL;
    p->data = e;
    q = Q->rear;
    q->next = p;
    Q->rear = p;
    return OK;
}

Status QueueExit(Queue *Q,ElemType *e)
{
    Node *q;
    if(Q == NULL) return ERR;
    if(Q->front == Q->rear) return ERR;
    q = Q->front->next;
    *e = q->data;
    if(q == Q->rear){
        Q->rear = Q->front;
    }else{
        Q->front->next = q->next; //q最后一个元素时没有next
    }
	free(q);
        return OK
}
