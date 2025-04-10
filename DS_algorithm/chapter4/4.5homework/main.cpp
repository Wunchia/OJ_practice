//读取10个元素 87  7 60 80 59 34 86 99 21  3，然后建立二叉查找树，
//中序遍历输出3  7 21 34 59 60 80 86 87 99，针对有序后的元素，
//存入一个长度为10的数组中，通过折半查找找到21的下标（下标为2），然后输出2
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct BSTnode{
    ElemType data;
    BSTnode *lchild,*rchild;
}BSTnode,*BST;

void Inorder(BST T,int *A){
    static int i=0;
    if(T!=NULL){
        Inorder(T->lchild,A);
        printf("%3d ",T->data);
        A[i++]=T->data;
        Inorder(T->rchild,A);
    }
}

int BST_insert(BST &T,ElemType a){
    BSTnode *pnew=NULL,*pcur=NULL,*parent=NULL;
    pnew=(BSTnode *)calloc(1,sizeof(BSTnode));
    pnew->data=a;
    if(T==NULL){
        T=pnew;
        return 1;
    }else{
        pcur=T;
        while(pcur!=NULL) {
            parent=pcur;
            if (a < pcur->data) {
                pcur = pcur->lchild;
            }else if(a > pcur->data){
                pcur=pcur->rchild;
            }else{
                return 0;
            }
        }
        if(a < parent->data){
            parent->lchild=pnew;
        }else{
            parent->rchild=pnew;
        }
        return 1;
    }
}

void Creat_BST(BST &T){
    ElemType a;
    int i=10;
    while(i>0){
        scanf("%d",&a);
        BST_insert(T,a);
        i--;
    }
}

int BinarySearch(int A[],ElemType key,int len){
    int low=0;
    int high=len-1;
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(key>A[mid]){
            low=mid+1;
        }else if(key<A[mid]){
            high=mid-1;
        }else{
            return mid;
        }
    }
    return -1;
}

int main(){
    BST T=NULL;
    int A[10];
    Creat_BST(T);
    Inorder(T,A);
    printf("\n");
    int pos=BinarySearch(A,21,10);
    printf("%d\n",pos);
    return 0;
}