#include "mystring.h"



int main(void)
{
    // char *p= "12345678900987654321";
    // char *q= "00";
    // ElemType *T = NULL;
    // StringInit(&T);
    // StringCopy(T,p);
    // printf("%d\n",StringCompare(p,q));
    // printf("%d\n",StringFind(p,q));
    ElemType *T = "bababaaabaa";
    ElemType *S = "ababaaaba";
    int next[StringLength(S)];
    printf("%d\n",KMP(T,S,next));
    return 0;
}