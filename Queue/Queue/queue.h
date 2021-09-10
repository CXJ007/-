#ifndef QUEUE_H
#define QUEUE_H

#define MAXSIZE  20
#define OK       1
#define ERR      0
typedef int      Status;
typedef int      ElemType;

typedef struct{
    ElemType data[MAXSIZE];
    int front;
    int rear;
}Queue;

#endif