//输入3 4 5 6 7 9999一串整数，9999代表结束，通过尾插法新建链表，
//查找第二个位置的值并输出，在2个位置插入99，输出为  3 99  4  5  6  7，
//删除第4个位置的值，打印输出为  3 99  4  6  7。
//
//输出函数如下：
//void PrintList(LinkList L)
//{
//    L = L->next;
//    while (L != NULL)
//    {
//        printf("%3d", L->data);//打印当前结点数据
//        L = L->next;//指向下一个结点
//    }
//    printf("\n");
//}

#include <stdio.h>
#include <stdlib.h>
typedef struct LNode{
    int data;
    LNode* next;
}LNode,*LinkList;

void TailInsert(LinkList &L,LNode *p,LNode *&r){
    p->next=r->next;
    r->next=p;
    r=p;
}

void PrintList(LinkList L){
    L = L->next;
    while (L!= NULL){
        printf("%3d", L->data);//打印当前结点数据
        L = L->next;//指向下一个结点
    }
    printf("\n");
}

void Create(LinkList &L){
    int i;
    scanf("%d",&i);
    LNode* r=L;
    while(r->next!=NULL){
        r=r->next;
    }
    while(i!=9999){
        LNode *temp=(LNode*)malloc(sizeof(LNode));
        temp->data=i;
        TailInsert(L,temp,r);
        scanf("%d",&i);
    }
}

void PosInsert(LinkList &L,int pos,int val){
    int i=pos;
    LNode *cur=L, *pre;
    while(i!=0&&cur!=NULL){
        pre=cur;
        cur=cur->next;
        i--;
    }
    if(NULL==cur){
        printf("false");
    }
    printf("%d\n",cur->data);
    LNode *p=(LNode*)malloc(sizeof(LNode));
    p->data=val;
    pre->next=p;
    p->next=cur;
}

void PosDelete(LinkList &L,int pos){
    int i=pos;
    LNode *cur=L, *pre;
    while(i!=0&&cur!=NULL){
        pre=cur;
        cur=cur->next;
        i--;
    }
    if(NULL==cur){
        printf("false");
    }
    pre->next=cur->next;
    free(cur);
}

int main(){
    LinkList L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    Create(L);
    PosInsert(L,2,99);
    PrintList(L);
    PosDelete(L,4);
    PrintList(L);
    return 0;
}