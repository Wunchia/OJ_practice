//
// Created by 16681 on 2025/4/7.
//

#ifndef INC_3_1BINARYTREE_FUNCTION_H
#define INC_3_1BINARYTREE_FUNCTION_H

#include <stdio.h>
#include <stdlib.h>
//树的结构体声明
typedef char TElemType;
typedef struct BTNode{
    TElemType data;
    BTNode *lchild,*rchild;
}BTNode,*BTree;

//建树辅助队列(实现一）
typedef struct tag{
    BTNode* data;
    tag *next;
}tag,*ptag;

//队列结构体定义及函数声明
typedef BTree ElemType;
typedef struct Lnode{//定义链表
    ElemType data;
    Lnode *next;
}Lnode,*LinkList;

typedef struct{//定义队列
    Lnode *front,*rear;
}LinkQueue;

void InitLQueue(LinkQueue &Q);
bool IsLQEmpty(LinkQueue Q);
bool EnLQueue(LinkQueue &Q,ElemType n);
bool DeLQueue(LinkQueue &Q,ElemType &n);

#endif //INC_3_1BINARYTREE_FUNCTION_H
