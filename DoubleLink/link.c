#include <stdio.h>
#include "link.h"

Status LinkInsert(Node *head,int i,ElemType e);
Status LinkDisplay(Node *head);
Status LinkDelet(Node *head,int i,ElemType *e);

int main(void)
{
    Node *Link = (Node *)malloc(sizeof(Node));
    if(Link == NULL) printf("init_err\n");
    Link->next = Link;
    Link->prior = Link;
    LinkInsert(Link,1,1);
    LinkInsert(Link,2,2);
    LinkInsert(Link,3,3);
    LinkInsert(Link,4,4);
    LinkInsert(Link,2,5);
    LinkDisplay(Link);
    ElemType data;
    LinkDelet(Link,4,&data);
    printf("%d\n",data);
    LinkDisplay(Link);
    
    return 0;
}

Status LinkInsert(Node *head,int i,ElemType e)
{
    int j = 1;
    Node *p,*q;
    p = head;
    if(head == NULL) return ERR;
    if(i < 1) return ERR;
    while(j < i){
        p = p->next;
        j++;
        if(p == head) break;
    }
    if(i != j) return ERR;
    q = (Node *)malloc(sizeof(Node));
    if(q == NULL) return ERR;
    q->data = e;
    q->prior = p;
    q->next = p->next;
    p->next->prior = q;
    p->next = q;
    return OK;
}

Status LinkDisplay(Node *head)
{
    Node *p = head;
    if(head == NULL) return ERR;
    p = p->next;
    while(p != head){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

Status LinkDelet(Node *head,int i,ElemType *e)
{
    int j;
    Node *p,*q;
    p = head;
    if(head == NULL) return ERR;
    for(j=0;j<i-1;j++){
        p = p->next;
        if(p == head) break;
    }
    if(j != i-1) return ERR;
    q = p->next;
    *e = q->data;
    p->next = q->next;
    q->next->prior = q;
    free(q);
}