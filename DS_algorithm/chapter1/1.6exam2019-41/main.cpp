#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct Lnode{
    ElemType data;
    Lnode *next;
}Lnode,*LinkList;

void PrintLink(LinkList L){
    Lnode *p=L->next;
    while(p!=NULL){
        printf("%3d",p->data);
        p=p->next;
    }
    printf("\n");
}

void HeadInsert(LinkList &L,Lnode *p){
    p->next=L->next;
    L->next=p;
}

void InitLink(LinkList &L){
    int i=6;
    while(i!=0){
        Lnode *p=(Lnode*)malloc(sizeof(Lnode));
        p->data=i;
        HeadInsert(L,p);
        i--;
    }
}

//解法1
void Reverse1(LinkList &L){
    Lnode* p;
    LinkList temp=L->next;
    L->next=NULL;
    while(temp!=NULL){
        p=temp;
        temp=temp->next;
        p->next=L->next;
        L->next=p;
    }
}

void Solution(LinkList &L){
    //找中点
    Lnode *scur=L,*ocur=L;
    while(scur!=NULL&&ocur!=NULL&&ocur->next!=NULL){
        scur=scur->next;
        ocur=ocur->next->next;
    }
    LinkList L2=(LinkList)malloc(sizeof (Lnode));
    L2->next=scur->next;
    scur->next=NULL;
    //逆置
    Reverse1(L2);
    PrintLink(L2);
    //插入
    Lnode *p=L->next,*pre,*q=L2->next;
    while(p!=NULL&&q!=NULL){
        pre=p;
        p=p->next;
        pre->next=q;
        q=q->next;
        pre->next->next=p;
    }
    PrintLink(L);
}

//解法2
void FindMid(LinkList &L1,LinkList &L2){
    L2=(LinkList)malloc(sizeof(Lnode));
    Lnode *ocur=L1->next,*scur=ocur;
    while(ocur!=NULL){
        ocur=ocur->next;
        if(ocur==NULL){
            break;
        }
        ocur=ocur->next;
        if(ocur==NULL){
            break;
        }
        scur=scur->next;
    }
    L2->next=scur->next;//L2指向后一段
    scur->next=NULL;//前一段的末尾置为NULL
}

void Reverse(LinkList &L){
    if(L->next==NULL||L->next->next==NULL){
        return;
    }
    Lnode  *r,*s,*t;
    r=L->next;
    s=r->next;
    t=s->next;
    r->next=NULL;
    while(t!=NULL){
        s->next=r;
        r=s;
        s=t;
        t=t->next;
    }
    s->next=r;
    L->next=s;
}

void Merge(LinkList L1,LinkList L2){
    Lnode *p=L1->next,*q=L2->next;
    Lnode *cur=p;
    while(p!=NULL&&q!=NULL){
        p=p->next;
        cur->next=q;
        q=q->next;
        cur=cur->next;
        cur->next=p;
        cur=cur->next;
    }
//    if(p!=NULL){
//        cur->next=p;
//    }
//    if(q!=NULL){
//        cur->next=q;
//    }
}

int main(){
    LinkList L=(LinkList)malloc(sizeof(Lnode));
    L->next=NULL;
    InitLink(L);
    PrintLink(L);
    LinkList A=NULL;
//    Solution(L);
    FindMid(L,A);
    Reverse(A);
    PrintLink(A);
    Merge(L,A);
    PrintLink(L);
    free(A);
    return 0;
}