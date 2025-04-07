#include <stdio.h>
#include <stdlib.h>
//树的结构体声明
typedef char TElemType;
typedef struct BTNode{
    TElemType data;
    BTNode *lchild,*rchild;
}BTNode,*BTree;

//队列结构体定义及函数声明
typedef BTree ElemType;
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

void InitBTree2(BTree &T){
    TElemType c;
    T=NULL;
    BTNode *pnew=NULL,*pnow=NULL;
    LinkQueue Q;
    InitLQueue(Q);
    while(scanf("%c",&c)){
        if(c=='\n'){
            break;
        }
        pnew=(BTNode*) calloc(1,sizeof(BTNode));
        pnew->data=c;
        if(T==NULL){
            T=pnew;
            EnLQueue(Q,pnew);
            DeLQueue(Q,pnow);
        }else{
            EnLQueue(Q,pnew);
            if(NULL==pnow->lchild){
                pnow->lchild=pnew;
            }else if(NULL==pnow->rchild){
                pnow->rchild=pnew;
                DeLQueue(Q,pnow);
            }
        }
    }
    while(!IsLQEmpty(Q)){
        DeLQueue(Q,pnow);
    }
}

void PreOrder(BTree T){
    if(T!=NULL) {
        printf("%c", T->data);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void MidOrder(BTree T){
    if(T!=NULL) {
        MidOrder(T->lchild);
        printf("%c", T->data);
        MidOrder(T->rchild);
    }
}

void PostOrder(BTree T){
    if(T!=NULL) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        printf("%c", T->data);
    }
}

//层序遍历
void LevelOrder(BTree T){
    LinkQueue Q;
    InitLQueue(Q);
    BTNode *p;
    EnLQueue(Q,T);
    while(!IsLQEmpty(Q)){
        DeLQueue(Q,p);
        putchar(p->data); //等价于 printf("%c",p->data);
        if(p->lchild){
            EnLQueue(Q,p->lchild);
        }
        if(p->rchild){
            EnLQueue(Q,p->rchild);
        }
    }
    printf("\n");
}

int main(){
    BTree T;
    InitBTree2(T);
    MidOrder(T);
    printf("\n");
    PostOrder(T);
    printf("\n");
    LevelOrder(T);
    return 0;
}