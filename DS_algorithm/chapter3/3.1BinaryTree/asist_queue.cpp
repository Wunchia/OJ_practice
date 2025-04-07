#include "function.h"
//链表实现队列
//函数定义
void InitLQueue(LinkQueue &Q){//带头结点方式
    Q.front=Q.rear=(LinkList) malloc(sizeof(Lnode));//头尾指向同一个节点
    Q.front->next=NULL;
}

bool IsLQEmpty(LinkQueue Q){
    if(Q.front->next==NULL){
        return true;
    }else{
        return false;
    }
}

bool EnLQueue(LinkQueue &Q,ElemType n){
    Lnode *p=(Lnode*) malloc(sizeof(Lnode));
    p->data=n;
    p->next=Q.rear->next;
    Q.rear->next=p;
    Q.rear=p;
    return true;
}

bool DeLQueue(LinkQueue &Q,ElemType &n){
    if(IsLQEmpty(Q)){
        return false;
    }else {
        Lnode *p = Q.front->next;
        Q.front->next = p->next;
        n = p->data;
        if(Q.rear==p){
            Q.rear=Q.front;
        }
        free(p);
        return true;
    }
}