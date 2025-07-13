#include "function.h"
//=========================================================================================
//二叉树层次建树
//实现一
void InitBTree1(BTree &tree){
    BTNode *pnew;//指向新创建的节点
    tree=NULL;//树根
    ptag head=NULL,tail=NULL,//辅助队列
    listpnew=NULL,//接收队列中的新节点
    pcur=NULL;//游标
    char c;
    while(scanf("%c",&c)){
        if(c=='\n'){
            break;
        }
        //calloc申请的空间大小为两个参数相乘,且会对申请的空间初始化赋值为0
        pnew=(BTNode *)calloc(1,sizeof(BTNode));
        pnew->data=c;
        listpnew=(ptag)calloc(1,sizeof(tag));
        listpnew->data=pnew;
        //树和辅助队列同时建立，一起往后走；辅助队列用于记录当前的插入位置，pcur=tail/2
        if(tree==NULL){
            tree=pnew;
            head=tail=listpnew;//初始化辅助队列
            pcur=listpnew;//指向当前新叶子需要插入的分支节点
        }else{
            tail->next=listpnew;
            tail=listpnew;//新叶子插入辅助队列
            if(pcur->data->lchild==NULL){
                pcur->data->lchild=pnew;
            }else if(pcur->data->rchild==NULL){
                pcur->data->rchild=pnew;
                pcur=pcur->next;//tail向后走两步，pcur才向后走一步，符合二叉树的规律
            }
        }
    }
    while(head){//回收辅助队列
        pcur=head;
        head=head->next;
        free(pcur);
    }
}

//实现二
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
//===============================================================================

//前中后序遍历
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
    InitBTree1(T);
//    InitBTree2(T);
    printf("----pre order----\n");
    PreOrder(T);
    printf("\n----mid order----\n");
    MidOrder(T);
    printf("\n----post order----\n");
    PostOrder(T);
    printf("\n----level order----\n");
    LevelOrder(T);
    return 0;
}