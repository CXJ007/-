#ifndef STACK_H
#define STACK_H

#define ERR 0
#define OK  1
#define MAXSIZE 50
typedef int ElemType;
typedef int Status;

typedef struct{
    ElemType data[MAXSIZE];
    int top1;
    int top2;
}Stack;




#endif