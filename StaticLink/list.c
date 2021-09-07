#include <stdio.h>
#include "list.h"

Status StaticLinkInit(Node * L);
int ListLength(Node *L);
Status StaticLinkInsert(Node *L,int i,ElemType e);
Status StaticLinkDisPlay(Node *L);
Status StaticLinkDelet(Node *L,int i,ElemType *e);
Status StaticLinkAllDelet(Node *L);

int main(void)
{
    Node *StaticList;
    StaticList = (Node *)malloc(MAXSIZE*sizeof(Node));
    StaticLinkInit(StaticList);
    //printf("%d   %d   %d\n",StaticList[0].cur,StaticList[10].cur,StaticList[MAXSIZE-1].cur);
    StaticLinkInsert(StaticList,1,1);
    StaticLinkInsert(StaticList,1,2);
    StaticLinkInsert(StaticList,1,3);
    StaticLinkInsert(StaticList,1,4);
    StaticLinkInsert(StaticList,2,5);
    StaticLinkDisPlay(StaticList);
    ElemType data;
    StaticLinkDelet(StaticList,2,&data);
    printf("%d\n",data);
    StaticLinkDisPlay(StaticList);
    StaticLinkInsert(StaticList,2,5);
    StaticLinkDisPlay(StaticList);
    StaticLinkAllDelet(StaticList);
    StaticLinkInsert(StaticList,1,1);
    StaticLinkInsert(StaticList,1,2);
    StaticLinkDisPlay(StaticList);
    return 0;
}

//数组最后一个是头节点第一个是备用节点
Status StaticLinkInit(Node *L)
{
    int i;
    if(L == NULL) return ERR;
    for(i=0;i<MAXSIZE-1;i++){
        L[i].cur = i+1;
    }
    L[MAXSIZE-1].cur = 0;
    return OK;
}

int ListLength(Node *L)
{
    int i,j;
    i = 0;
    j = L[MAXSIZE-1].cur;
    while(j){
        j = L[j].cur; //到备用节点结束
        i++;
    }
    return i;
}

Status StaticLinkInsert(Node *L,int i,ElemType e)
{
    int j,k,q;
    if(L == NULL) return ERR;
    if(ListLength(L) >= MAXSIZE-2) return ERR;
    if(i<1 || i>ListLength(L)+1) return ERR;
    j = MAXSIZE-1;
    for(q=0;q<i-1;q++){
        j = L[j].cur;
    }
    k = L[0].cur;//找到备用节点 0
    L[0].cur = L[k].cur;//更新备用节点
    L[k].data = e;
    L[k].cur = L[j].cur;
    L[j].cur = k;
    return OK;
}

Status StaticLinkDisPlay(Node *L)
{
    int i;
    if(L == NULL) return ERR;
    i = L[MAXSIZE-1].cur;
    while(i){
        printf(" %d",L[i].data);
        i = L[i].cur;  
    }
    printf("\n");
    return OK;
}

Status StaticLinkDelet(Node *L,int i,ElemType *e)
{
    int j,q,k;
    if(L == NULL) return ERR;
    if(i<1 || i>ListLength(L)) return ERR;
    j = MAXSIZE-1;
    for(q=0;q<i-1;q++){
        j = L[j].cur;
    }
    k = L[j].cur;
    *e = L[k].data;
    L[j].cur = L[k].cur;
    L[k].cur = L[0].cur;
    L[0].cur = k;
    return OK;
}

Status StaticLinkAllDelet(Node *L)
{
    int i,j;
    if(L == NULL) return ERR;
    j = ListLength(L);
    for(i=0;i<=j;i++){
        L[i].cur=i+1;
    }
    L[MAXSIZE-1].cur = 0;
    return OK;
}

