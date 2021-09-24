#ifndef TREE_H
#define TREE_H

#define ERR 0
#define OK 1
typedef int Status;
typedef char ElemType;
typedef struct Node{
    ElemType data;
    struct Node *lchild,*rchild;  
}Node,*BiTree;





#endif