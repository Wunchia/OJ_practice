//输入3 4 5 6 7 9999一串整数，9999代表结束，通过头插法新建链表，并输出，通过尾插法新建链表并输出。
//注意输出要采用如下代码（因为OJ判题对空格敏感，因此需要用下面的打印代码来做）：
// //打印链表中每个结点的值
//void PrintList(LinkList L){
//    L=L->next;
//    while(L!=NULL){
//        printf("%d",L->data);//打印当前结点数据
//        L=L->next;//指向下一个结点
//        if(L!=NULL){
//            printf(" ");
//        }
//    }
//    printf("\n");
//}

#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct Lnode{
    ElemType data;
    Lnode *next;
}Lnode,*LinkList;

//打印链表中每个结点的值
void PrintList(LinkList L){
    L=L->next;
    while(L!=NULL){
        printf("%d",L->data);//打印当前结点数据
        L=L->next;//指向下一个结点
        if(L!=NULL){
            printf(" ");
        }
    }
    printf("\n");
}

//头插建表
void HeadCreate(LinkList &L,ElemType i){
    Lnode *p=(Lnode*)malloc(sizeof(Lnode));
    p->data=i;
    p->next=L->next;
    L->next=p;
}

//尾插建表
void TailCreate(LinkList &L,ElemType i){
    Lnode *p=(Lnode*)malloc(sizeof(Lnode));
    p->data=i;
    Lnode *cur=L;
    while(cur->next!=NULL){
        cur=cur->next;
    }
    p->next=cur->next;
    cur->next=p;
}


int main(){
    LinkList L1=(Lnode*)malloc(sizeof(Lnode));
    L1->next=NULL;
    LinkList L2=(Lnode*)malloc(sizeof(Lnode));
    L2->next=NULL;
    int temp[100];
    int i,j=0;;
    scanf("%d",&i);
    while(i!=9999){
        temp[j]=i;
        j++;
        HeadCreate(L1,i);
        scanf("%d",&i);
    }
    PrintList(L1);
    int limit=j;
    for(j=0;j<limit;j++){
        i=temp[j];
        TailCreate(L2,i);
    }
    PrintList(L2);
    return 0;
}