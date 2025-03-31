#include <stdio.h>
#include <stdlib.h>

#define MaxSize 6
typedef int ElemType;
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
//顺序表实现循环队列
typedef struct{
   ElemType data[MaxSize];
   int front,rear;
}SqQueue;

void InitQueue(SqQueue &Q){
    Q.front=Q.rear=0;
}

bool IsEmpty(SqQueue &Q){
    return Q.front==Q.rear;
}

bool EnQueue(SqQueue &Q,ElemType n){
    if(Q.front!=(Q.rear+1)%MaxSize) {
        Q.data[Q.rear] = n;
        Q.rear = (Q.rear + 1) % MaxSize;
        return true;
    }else{
        return false;
    }
}

bool DeQueue(SqQueue &Q,ElemType &n){
    if(Q.rear!=Q.front){
        n=Q.data[Q.front];
        Q.front=(Q.front+1)%MaxSize;
        return true;
    }else{
        return false;
    }
}
//--------------------------------------------------------------------------
void test01(){
    //顺序表实现循环队列
    SqQueue Q;
    ElemType n;
    bool ret;
    //初始化
    InitQueue(Q);
    //判空
    ret=IsEmpty(Q);
    if(ret){
        printf("Queue is empty\n");
    }else{
        printf("Queue is not empty\n");
    }

    //出队
    ret=DeQueue(Q,n);
    if(ret){
        printf("%d deleted from queue\n",n);
    }else{
        printf("delete fail\n");
    }
    EnQueue(Q,3);
    ret=DeQueue(Q,n);
    if(ret){
        printf("%d deleted from queue\n",n);
    }else{
        printf("delete fail\n");
    }

    //入队
    EnQueue(Q,1);
    EnQueue(Q,2);
    EnQueue(Q,3);
    EnQueue(Q,4);
    ret=EnQueue(Q,5);
    if(ret){
        printf("enter success\n");
    }else{
        printf("enter fail\n");
    }
    ret=EnQueue(Q,6);
    if(ret){
        printf("enter success\n");
    }else{
        printf("enter fail\n");
    }
};

//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
//链表实现队列
typedef struct Lnode{//定义链表
    ElemType data;
    Lnode *next;
}Lnode,*LinkList;

typedef struct{//定义队列
    Lnode *front,*rear;
}LinkQueue;

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

//--------------------------------------------------------------------------
void test02(){
    LinkQueue Q;
    ElemType n;
    bool ret;
    //初始化
    InitLQueue(Q);
    //判空
    ret= IsLQEmpty(Q);
    if(ret){
        printf("LinkQueue is empty\n");
    }else{
        printf("LinkQueue is not empty\n");
    }
    //===================================
    //出入队
    //队空时删除
    ret=DeLQueue(Q,n);
    if(ret){
        printf("deleted %d from LinkQueue\n",n);
    }else{
        printf("delete from LinkQueue failed\n");
    }
    //插入
    EnLQueue(Q,1);
    ret= IsLQEmpty(Q);
    if(ret){
        printf("LinkQueue is empty\n");
    }else{
        printf("LinkQueue is not empty\n");
    }
    //插入后将队列删空
    ret=DeLQueue(Q,n);
    if(ret){
        printf("deleted %d from LinkQueue\n",n);
    }else{
        printf("delete from LinkQueue failed\n");
    }
    ret= IsLQEmpty(Q);
    if(ret){
        printf("LinkQueue is empty\n");
    }else{
        printf("LinkQueue is not empty\n");
    }
    //再插入
    EnLQueue(Q,4);
    EnLQueue(Q,3);
    EnLQueue(Q,2);
    EnLQueue(Q,1);
    ret=DeLQueue(Q,n);//队不空时删除
    if(ret){
        printf("deleted %d from LinkQueue\n",n);
    }else{
        printf("delete from LinkQueue failed\n");
    }
}

//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
int main(){
    //顺序表实现循环队列
    test01();
    printf("============================\n");
    //链表实现队列
    test02();
    return 0;
}