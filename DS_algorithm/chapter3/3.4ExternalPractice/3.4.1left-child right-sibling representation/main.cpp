#include <stdio.h>
#include <stdlib.h>

typedef char Elemtype;

typedef struct node{//用孩子兄弟表示法表示森林
    Elemtype data;
    struct node *child,*sibling;
}*Tree;

//建树辅助队列
typedef struct tag{
    node* data;
    tag *next;
}tag,*ptag;

//建树
void InitTree(Tree &t){
    node *pnew;//指向新创建的节点
    t=NULL;//树根
    ptag head=NULL,tail=NULL,//辅助队列
    listpnew=NULL,//接收队列中的新节点
    pcur=NULL;//游标
    char c;
    while(scanf("%c",&c)){
        if(c=='\n'){
            break;
        }
//calloc申请的空间大小为两个参数相乘,且会对申请的空间初始化赋值为0
        pnew=(node *)calloc(1,sizeof(node));
        pnew->data=c;
        listpnew=(ptag)calloc(1,sizeof(tag));
        listpnew->data=pnew;
//树和辅助队列同时建立，一起往后走；辅助队列用于记录当前的插入位置，pcur=tail/2
        if(t==NULL){
            t=pnew;
            head=tail=listpnew;//初始化辅助队列
            pcur=listpnew;//指向当前新叶子需要插入的分支节点
        }else{
            tail->next=listpnew;
            tail=listpnew;//新叶子插入辅助队列
            if(pcur->data->child==NULL){
                pcur->data->child=pnew;
            }else if(pcur->data->sibling==NULL){
                pcur->data->sibling=pnew;
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

int CountLeaves(Tree t){
    if(t==NULL){
        return 0;
    }else if(t->child==NULL){
        return 1+ CountLeaves(t->sibling);
    }else{
        return CountLeaves(t->child)+ CountLeaves(t->sibling);
    }
}

int CountDepth(Tree t){
    int hc=0,hs=0;//左子树孩子分支的高度记为hc，右子树兄弟分支的高度记为hs
    if(t==NULL){
        return 0;
    }else{
        hc= CountDepth(t->child);
        hs= CountDepth(t->sibling);
        if((hc+1)>hs){
            return hc+1;
        }else{
            return hs;
        }
    }

}

int main() {
    Tree limber;
    InitTree(limber);
    int count=0,height=-1;
    count=CountLeaves(limber);
    height= CountDepth(limber);
    printf("counts of leaves is %d,Height of this tree is %d",count,height);
    return 0;
}

