#include "mystring.h"

Status StringInit(ElemType **T)
{
    ElemType *p = NULL;
    if(*T != NULL) return ERR;
    p = (ElemType *)malloc(sizeof(ElemType)*MAXSIZE);
    if(p == NULL) return ERR;
    *T = p;
    return OK;
}

int StringLength(ElemType *T)
{
    int i = 0;
    char p;
    if(T == NULL) return -1;
    p = *T;
    while(p != '\0'){
        i++;
        p = *(T+i);
        if(i >= MAXSIZE) return -1;
    }
    return i;
}

Status StringCopy(ElemType *T,ElemType *S)
{
    int i = 0;
    if(T == NULL) return ERR;
    if(StringLength(S) > MAXSIZE) return ERR;
    for(i=0;i<MAXSIZE;i++){
        *(T+i) = *(S+i);
        if(*(S+i) == '\0') break;
    }
    return OK;
}

Status StringClear(ElemType *T)
{
    if(T == NULL) return ERR;
    T = (ElemType *)memset((void *)T,'\0',sizeof(ElemType)*MAXSIZE);
    return OK;
}

int StringCompare(ElemType *T,ElemType *S)
{
    int i,j,k;
    j = StringLength(T);
    k = StringLength(S);
    if(j<k) i = k;
    else i = j;
    for(k=0;k<i;k++){
        //if(*(T+k)=='\0' || *(S+k)=='\0')   '\0' = 0
        if(*(T+k) != *(S+k)) return *(T+k)-*(S+k);
    }
    return 0;
}

int StringFind(ElemType *T,ElemType *S)
{
    int i=0,j=0,k=0;
    while(i<=StringLength(T)){
        if(*(S+j) != '\0'){
            if(*(T+i) == *(S+j)) j++;
            else {j=0;k++,i=k-1;}
        }else{
            return k+1;
        }
        i++;
    }
    return -1;
}

Status GetNext(ElemType *T,int *next)
{
    int i = 0;
    int j = -1;
    next[0] = -1;
    if(T==NULL || next==NULL) return ERR;
    while(i < StringLength(T)){
        if(j==-1 || T[j]==T[i]){
            j++;
            i++;
            next[i] = j;
            printf("%d",j);
        }else{
            j = next[j];
        }
    }
    printf("\n");
    return OK;
}

Status GetNextval(ElemType *T,int *next)
{
    int i = 0;
    int j = -1;
    next[0] = -1;
    if(T==NULL || next==NULL) return ERR;
    while(i < StringLength(T)){
        if(j==-1 || T[j]==T[i]){//必须J==-1在前面不再T的范围了
            j++;
            i++;
            if(T[i] != T[j]) next[i] = j;
            else next[i] = next[j];
            printf("%d",next[i]);
        }else{
            j = next[j];//
        }
    }
    printf("\n");
    return OK;
}

//这个是书上的有问题ababaaaba 结果是011231123   应该是 011234223 //上面的结果是-100123112
//并且他会缺少最后一个next //而且这个缺少字符01的对比
//应该是树上第一个储存的是字长；
// Status GetNext(ElemType *T,int *next)
// {
//     int i = 1;
//     int j = 0;
//     next[0] = 0;
//     if(T==NULL || next==NULL) return ERR;
//     while(i < StringLength(T)){
//         if(j==0 || T[j]==T[i]){
//             j++;
//             i++;
//             next[i-1] = j;
//         }else{
//             j = next[j-1];//
//         }
//     }
//     return OK;
// }

int KMP(ElemType *T,ElemType *S,int *next)
{
    int i = 0;
    int j = 0;
    if(T == NULL) return -1;
    if(GetNextval(S,next) == ERR) return -1;
    while(T[i]!='\0' && j<StringLength(S)){
        if(j==-1 || T[i]==S[j]){
            i++;
            j++;
        }else{
            j = next[j];
        }
    }
    if(S[j]=='\0') return i-StringLength(S)+1;
    else return -1;

}