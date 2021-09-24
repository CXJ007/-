#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void TreeBiCreatPre(BiTree *root);
void TreePreDisplay(BiTree *root);
void TreeInDisplay(BiTree *root);
void TreeBackDisplay(BiTree *root);

int main(void)
{
    BiTree root;
    TreeBiCreatPre(&root);
    TreePreDisplay(&root);
    printf("\n");
    TreeInDisplay(&root);
    printf("\n");
    TreeBackDisplay(&root);
    printf("\n");
    return 0;
}

void TreeBiCreatPre(BiTree *root)
{
   ElemType ch;
   scanf("%c",&ch);
   if(ch == '#'){
       *root = NULL;
   }else{
       *root = (Node *)malloc(sizeof(Node));
       if(*root == NULL) exit(1);
       (*root)->data = ch;
       TreeBiCreatPre(&((*root)->lchild));
       TreeBiCreatPre(&((*root)->rchild));
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
    TreeInDisplay(&((*root)->lchild));
    TreeInDisplay(&((*root)->rchild));
    printf("%c ",(*root)->data);
}