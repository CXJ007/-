#ifndef STACK_H
#define STACK_H

#define ERR 0
#define OK  1
typedef int ElemType;
typedef int Status;

typedef struct Node{
    ElemType data;
    struct Node *next;
}Node;

typedef struct{
    Node *top;
    int count;
}LinkStack;


#endif