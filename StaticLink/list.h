#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE  50
#define OK       1
#define ERR      0
typedef int      Status;
typedef int      ElemType;

typedef struct{
    ElemType data;
    int cur;
}Node;

#endif