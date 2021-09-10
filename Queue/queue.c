#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Status QueueInit(Queue **Q);

int main(void)
{
    Queue *CircleQueue = NULL;
    QueueInit(&CircleQueue);
    
    // printf("%d",CircleQueue->front);

    return 0;
}

Status QueueInit(Queue **Q)
{
    Queue *p = NULL;
    //p = *Q;//P要被释放放在后面
    p = (Queue *)malloc(sizeof(Queue));
    if(p == NULL) return ERR;
    p->front = 0;
    p->rear = MAXSIZE-1;
    *Q = p;
    return OK;
}