#include <stdio.h>
#include <stdlib.h>
//树的结构体声明
typedef int TElemType;
typedef struct BTNode{
    TElemType data;
    BTNode *lchild,*rchild;
}BTNode,*BTree;
//建树辅助队列(实现一）
typedef struct tag{
    BTNode* data;
    tag *next;
}tag,*ptag;
//二叉树层次建树
//实现一
void InitBTree1(BTree &tree){
    BTNode *pnew;//指向新创建的节点
    tree=NULL;//树根
    ptag head=NULL,tail=NULL,//辅助队列
    listpnew=NULL,//接收队列中的新节点
    pcur=NULL;//游标
    int c;
    while(scanf("%d",&c)){
        if(c==-1){
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

//题解
int wpl_PreOrder(BTree T,int depth){
    static int wpl=0;//静态局部变量和全局变量类似 只会初始化一次
    if(T!=NULL){
        if(T->lchild==NULL&&T->rchild==NULL){
           wpl+=depth*T->data;
        }
        wpl_PreOrder(T->lchild,depth+1);
        wpl_PreOrder(T->rchild,depth+1);
    }
    return wpl;
}

int WPL(BTree T){
    return wpl_PreOrder(T,0);
}

int main(){
    BTree T;
    InitBTree1(T);
    printf("%d",WPL(T));
    return 0;
}