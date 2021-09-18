#ifndef MYSTRING_H
#define MYSTRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERR 0
#define OK  1
#define MAXSIZE 50
typedef char ElemType;
typedef int Status;


Status StringInit(ElemType **T);
int StringLength(ElemType *T);
Status StringCopy(ElemType *T,ElemType *S);
Status StringClear(ElemType *T);
int StringCompare(ElemType *T,ElemType *S);
int StringFind(ElemType *T,ElemType *S);
Status GetNext(ElemType *T,int *next);
int KMP(ElemType *T,ElemType *S,int *next);

#endif