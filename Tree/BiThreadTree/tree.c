#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void TreeBiCreat(BiTree *root);
void TreePreDisplay(BiTree *root);
void TreeInDisplay(BiTree *root);
void TreeBackDisplay(BiTree *root);
void InThread0(BiTree root,BiTree *pre);
void InThread(BiTree root,BiTree *head);
Status TreeInThreadDisplay(BiTree head);

int main(void)
{
    BiTree root;
    TreeBiCreat(&root);
    TreePreDisplay(&root);
    printf("\n");
    TreeInDisplay(&root);
    printf("\n");
    TreeBackDisplay(&root);
    printf("\n");
    BiTree head = (BiTree)malloc(sizeof(Node));
    InThread(root,&head);
    TreeInThreadDisplay(head);
    return 0;
}

void TreeBiCreat(BiTree *root)
{
   ElemType ch;
   scanf("%c",&ch);
   if(ch == '#'){
       *root = NULL;
   }else{
       *root = (Node *)malloc(sizeof(Node));
       if(*root == NULL) exit(1);
       (*root)->data = ch;
       TreeBiCreat(&((*root)->lchild));
       TreeBiCreat(&((*root)->rchild));
   }
}

void TreePreDisplay(BiTree *root)
{
    if(*root == NULL) return;
    printf("%c ",(*root)->data);
    TreePreDisplay(&((*root)->lchild));
    TreePreDisplay(&((*root)->rchild));
}

void TreeInDisplay(BiTree *root)
{
    if(*root == NULL) return;
    TreeInDisplay(&((*root)->lchild));
    printf("%c ",(*root)->data);
    TreeInDisplay(&((*root)->rchild));
}

void TreeBackDisplay(BiTree *root)
{
    if(*root == NULL) return;
    TreeBackDisplay(&((*root)->lchild));
    TreeBackDisplay(&((*root)->rchild));
    printf("%c ",(*root)->data);
}

void InThread0(BiTree root,BiTree *pre)
{
    if(root != NULL){
        InThread0(root->lchild,pre);
        if(root->lchild == NULL){
            root->ltag = Thread;
            root->lchild = *pre;//当前节点的前驱
        }
        if((*pre)->rchild == NULL){
            (*pre)->rtag = Thread;
            (*pre)->rchild = root;//上一节点的后区
        }
        *pre = root;
        InThread0(root->rchild,pre);
    }
}

void InThread(BiTree root,BiTree *head)
{
    if(*head == NULL) *head = (BiTree) malloc(sizeof(Node));
    if(*head == NULL) exit(1);
    (*head)->ltag = Link;
    (*head)->rtag = Thread;
    (*head)->rchild = *head;
    if(root == NULL){
        (*head)->lchild = *head; //root为NULL 自己指向自己
    }else{
        (*head)->lchild = root;
        BiTree pre = *head; //中序遍历的第一个节点的前驱为head
        InThread0(root,&pre);
        pre->rtag = Thread;//线索化结束后pre为最后一个节点
        pre->rchild = *head; //pre的后驱改为head
        (*head)->rchild = pre;
    }
}

Status TreeInThreadDisplay(BiTree head)
{
    BiTree p = head->lchild;
    if(head == NULL)return ERR;
    while(p != head){ //由原有关系找到叶节点然后由下往上按照线索遍历
        while(p->ltag == Link) p = p->lchild;
        printf("%c ",p->data);
        while(p->rtag==Thread && p->rchild!=head){
            p = p->rchild;
            printf("%c ",p->data);
        }
        p = p->rchild;
    }
    return OK;
}