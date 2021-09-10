#ifndef QUEUE_H
#define QUEUE_H

#define OK       1
#define ERR      0
typedef int      Status;
typedef int      ElemType;

typedef struct Node{
    ElemType data;
    struct Node *next;
}Node;

typedef struct{
    Node *front,*rear;
}Queue;

#endif