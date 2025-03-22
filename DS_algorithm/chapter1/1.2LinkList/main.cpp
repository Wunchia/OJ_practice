#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct Lnode{
    ElemType data;
    Lnode *next;
}LNode,*LinkList;

//带头节点

//函数声明
bool HeadInsert(LinkList &L,Lnode *p);
bool TailInsert(LinkList &L,Lnode *p);

//初始化链表
bool ListInit(LinkList &L){
    L=(Lnode*)malloc(sizeof(Lnode));
    L->next=NULL;
    return true;
}

bool HeadFiveNode(LinkList &L){//通过头插法向链表内插入五个节点
    int i=5;
    for(int i=5;i>0;i--){
        Lnode *p=(Lnode*)malloc(sizeof(Lnode));
        p->data=i;
        HeadInsert(L,p);
    }
    return true;
}

bool TailFiveNode(LinkList &L){//通过尾插法向链表内插入五个节点
    int i=5;
    for(int i=5;i>0;i--){
        Lnode *p=(Lnode*)malloc(sizeof(Lnode));
        p->data=6-i;
        TailInsert(L,p);
    }
    return true;
}

//插入节点
bool HeadInsert(LinkList &L,Lnode *p){//头插
    p->next=L->next;
    L->next=p;
    return true;
}

bool TailInsert(LinkList &L,Lnode *p){//尾插
    Lnode *cur=L;
    while(cur->next!=NULL){
        cur=cur->next;
    }
    p->next=cur->next;
    cur->next=p;
    return true;
}

bool RandInsert(LinkList &L,Lnode *p,int pos){
    if(pos<1){
        return false;
    }
    Lnode *cur=L,*pre;
    for(int i=pos;i>0;i--){
        pre=cur;
        if(pre==NULL){
            return false;
        }
        cur=cur->next;
    }
    p->next=cur;
    pre->next=p;
    return true;
}


//删除节点
bool ListDel(LinkList &L,int pos,int &val){
    if(pos<=0){
        return false;
    }
    int i=pos;
    Lnode* cur=L,*pre;
    while(cur!=NULL&&i>0){
        pre=cur;
        cur=cur->next;
        i--;
    }
    if(cur==NULL){
        return false;
    }
    val=cur->data;
    pre->next=cur->next;
    free(cur);
    return true;
}

//按位查
bool IdSearch(LinkList L,int pos,int &val){
    if(pos<1){
        return false;
    }
    Lnode *cur=L;
    while(cur!=NULL&&pos>0){
        cur=cur->next;
        pos--;
    }
    if(cur==NULL){
        return false;
    }
    val=cur->data;
    return true;
}

//按值查
bool ValSearch(LinkList L,int val,Lnode *&node){
    Lnode *cur=L;
    while(cur!=NULL){
        cur=cur->next;
        if(cur->data==val){
            node=cur;
            return true;
        }
    }
    return false;
}

//修改节点
bool ListChange(LinkList &L,int pos,int val){
    if(pos<1){
        return false;
    }
    Lnode *cur=L;
    while(cur!=NULL&&pos!=0){
        cur=cur->next;
        pos--;
    }
    if(cur==NULL){
        return false;
    }
    cur->data=val;
    return true;
}

//销毁链表
bool DestroyList(LinkList &L){
    LNode *p=L,*pre;
    while(p!=NULL){
        pre=p;
        p=p->next;
        free(pre);
    }
    printf("destroy success\n");
    return true;
}

//打印链表信息
void PrintList(LinkList L){
    Lnode*p=L->next;
    int len=0;
    while(p!=NULL){
        printf("%3d ",p->data);
        p=p->next;
        len++;
    }
    printf("\nlen=%3d\n-----------\n",len);
}

int main(){
    LinkList L;
    //测试用节点
    Lnode *node=(Lnode*)malloc(sizeof(Lnode));
    node->data=66;
    bool ret;//接收函数返回值
    int del;//接收删除节点的值
    int val;//接收查找到的值

    ListInit(L);
    HeadFiveNode(L);
    printf("before operate\n");
    PrintList(L);

    //插入
    ret=RandInsert(L,node,3);
    if(ret){
        printf("random insert success\n");
    }else{
        printf("random insert fail\n");
    }
    PrintList(L);

    //删除
    ret=ListDel(L,3,del);
    if(ret){
        printf("delete %d success\n",del);
    }else{
        printf("delete fail\n");
    }
    PrintList(L);

    //按位查
    ret=IdSearch(L,4,val);
    if(ret){
        printf("find %d though id success\n",val);
    }else{
        printf("id search fail\n");
    }
    PrintList(L);

    //按值查
    ret=ValSearch(L,3,node);
    if(ret){
        printf("find %d though val success\n",node->data);
    }else{
        printf("val search fail\n");
    }
    PrintList(L);

    //修改
    ret=ListChange(L,3,66);
    if(ret){
        printf("change success\n");
    }else{
        printf("change fail\n");
    }
    PrintList(L);

    //回收内存
    DestroyList(L);
    return 0;
}