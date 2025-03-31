#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct Lnode{
    ElemType data;
    Lnode *next;
}Lnode,*LinkList;

typedef struct LQueue{
    Lnode *front,*rear;
};

//初始化链表实现的循环队列
void InitRQueue(LQueue &Q){
    Q.front=Q.rear=(LinkList)malloc(sizeof(Lnode));
    Q.rear->next=Q.front;
}

bool IsEmpty(LQueue Q){
    if(Q.front==Q.rear){
        return true;
    }else{
        return false;
    }
}

//bool EnRQueue(LQueue &Q,ElemType n){
//    Lnode *p=(LinkList)malloc(sizeof(Lnode));
//    p->data=n;
//    p->next=Q.rear->next;
//    Q.rear->next=p;
//    Q.rear=p;
//    return true;
//}

//队列空间只增不减版本
bool EnRQueue(LQueue &Q,ElemType n){
    if(Q.rear->next==Q.front){
        Lnode *p=(LinkList)malloc(sizeof(Lnode));
        p->data=n;
        p->next=Q.rear->next;
        Q.rear->next=p;
        Q.rear=p;
        return true;
    }else{
        Q.rear=Q.rear->next;
        Q.rear->data=n;
        return true;
    }
}


//bool DeRQueue(LQueue &Q,ElemType &n){
//    if(IsEmpty(Q)){
//        return false;
//    }else{
//        Lnode *p=Q.front->next;
//        Q.front->next=p->next;
//        n=p->data;
//        if(p==Q.rear){
//            Q.rear=Q.front;
//        }
//        free(p);
//        return true;
//    }
//}

//队列空间只增不减版本
bool DeRQueue(LQueue &Q,ElemType &n){
    if(IsEmpty(Q)){
        return false;
    }else{
        Q.front=Q.front->next;
        n=Q.front->data;
        return true;
    }
}

int main(){
    LQueue Q;
    ElemType n;
    bool ret;
    InitRQueue(Q);
    ret=IsEmpty(Q);
    if(ret){
        printf("RQueue is empty\n");
    }else{
        printf("RQueue is not empty\n");
    }
    ret=DeRQueue(Q,n);
    if(ret){
        printf("Deleted %d from RQueue success\n",n);
    }else{
        printf("Delete failed\n");
    }
    EnRQueue(Q,1);
    ret=IsEmpty(Q);
    if(ret){
        printf("RQueue is empty\n");
    }else{
        printf("RQueue is not empty\n");
    }
    ret=DeRQueue(Q,n);
    if(ret){
        printf("Deleted %d from RQueue success\n",n);
    }else{
        printf("Delete failed\n");
    }
    ret=IsEmpty(Q);
    if(ret){
        printf("RQueue is empty\n");
    }else{
        printf("RQueue is not empty\n");
    }
    EnRQueue(Q,4);
    EnRQueue(Q,3);
    EnRQueue(Q,2);
    EnRQueue(Q,1);
    while(!IsEmpty(Q)){
    ret=DeRQueue(Q,n);
    if(ret){
        printf("Deleted %d from RQueue success\n",n);
    }else{
        printf("Delete failed\n");
    }
    }
    return 0;
}