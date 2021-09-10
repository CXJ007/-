#include <stdio.h>
#include "link.h"


Status LinkInsert(Node *hand,int i,ElemType e);
Status LinkRead(Node *head,int i,ElemType *e);
Status LinkDisplay(Node *head);
Status LinkDelet(Node *head,int i,ElemType *e);
Status LinkCreatHead(Node *head,int i);
Status LinkCreatTail(Node *head,int i);
Status LinkAllDelet(Node **head);

int main(void)
{
    Node *head,*p;
    head = (Node *)malloc(sizeof(Node));
    if(head == NULL) printf("creat_err\n");
    // LinkInsert(head,1,1);
    // LinkInsert(head,2,2);
    // LinkInsert(head,3,3);
    // LinkInsert(head,1,4);
    // LinkInsert(head,2,5);
    // LinkDisplay(head);
    // ElemType data;
    // LinkDelet(head,5,&data);
    // printf("%d\n",data);
    // LinkDisplay(head);
    LinkCreatHead(head,5);
    LinkDisplay(head);
    LinkCreatTail(head,5);
    LinkDisplay(head);
    LinkAllDelet(&head);
    if(LinkDisplay(head) == ERR) printf("Delet\n");
    return 0;
}


Status LinkInsert(Node *head,int i,ElemType e)
{
    int j;
    Node *p,*q;
    p = head;
    j = 1;
    if(p == NULL) return ERR;
    while(j<i && p!=NULL){  //在i后一位置插入
        p = p->next;
        j++;
    }
    if(j!=i) return ERR;
    q = (Node *)malloc(sizeof(Node));
    if(q == NULL) return ERR;
    q->data = e;
    q->next = p->next;
    p->next = q;
    return OK;
}


Status LinkRead(Node *head,int i,ElemType *e)
{
    int j=0;
    Node *p;
    p = head;
    if(p == NULL) return ERR;
    if(p->next == NULL) return ERR;
    while(p!=NULL && j<i){ //直接找到i
        p = p->next;
        j++;
    }
    if(j!=i) return ERR;
    *e = p->data;
    return OK;
}

Status LinkDisplay(Node *head)
{
    Node *p;
    p = head;
    if(p == NULL) return ERR;
    p = p->next;
    while(p != NULL){
        printf(" %d",p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}

Status LinkDelet(Node *head,int i,ElemType *e)
{
    int j=1;
    Node *p = head;
    Node *q;
    if(p == NULL) return ERR;
    if(p->next == NULL) return ERR;
    while(p!=NULL && j<i){
        p = p->next;
        j++; 
    }
    if(j != i) return ERR;
    *e = p->next->data;
    q = p->next;
    p->next = q->next;
    free(q);
    return OK;
}

Status LinkCreatHead(Node *head,int i)
{
    int j;
    Node *p = head,*q;
    if(p == NULL) return ERR;
    if(i<1) return ERR;
    for(j=0;j<i;j++){
        q = (Node *)malloc(sizeof(Node));
        q->data = j+1;
        q->next = p->next;
        p->next = q;
    }
    return OK;
}

Status LinkCreatTail(Node *head,int i)
{
    int j=0;
    Node *p=head,*q=NULL,*k=NULL;
    if(p == NULL) return ERR;
    if(i < 1) return ERR;
    while(p != NULL){
        q = p;  //找到null前一个
        p = p->next;
    }
    for(j=0;j<i;j++){
        k = (Node *)malloc(sizeof(Node));
        k->data = j+1;
        k->next = q->next;
        q->next = k;
        q = k;  //更新最后节点
    }
    return OK;
}

Status LinkAllDelet(Node **head)
{
    Node *p,*q;
    if(*head == NULL) return OK;
    p = (*head)->next;
    while(p != NULL){
        q = p->next;
        free(p);
        p = q;
    }
    free(*head);//变成野指针了不是NULL；
    *head = NULL;
    return OK;
}
