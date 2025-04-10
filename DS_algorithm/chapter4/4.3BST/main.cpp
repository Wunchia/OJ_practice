#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct BSTnode{
    ElemType data;
    BSTnode *lchild,*rchild;
}BSTnode,*BST;

void Inorder(BST T){
    if(T!=NULL){
        Inorder(T->lchild);
        printf("%3d ",T->data);
        Inorder(T->rchild);
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
    while(scanf("%d",&a)){
        if(a==9999){
            break;
        }
        BST_insert(T,a);
    }
}

BST Search(BST T,ElemType key){
    BST pcur=T;
    while(pcur!=NULL){
        if(key<pcur->data){
            pcur=pcur->lchild;
        }else if(key>pcur->data){
            pcur=pcur->rchild;
        }else{
            return pcur;
        }
    }
    return pcur;
}

void BST_Delete(BST &T,ElemType key){
    if(T==NULL){
        return;
    }
    if(T->data>key){
        BST_Delete(T->lchild,key);
    }else if(T->data<key){
        BST_Delete(T->rchild,key);
    }else{//找到了要删除的节点
        if(T->lchild==NULL){
            BST temp=T;
            T=T->rchild;
            free(temp);
        }else if(T->rchild==NULL){
            BST temp=T;
            T=T->lchild;
            free(temp);
        }else{//左右子树都不为空
            BST temp=T->rchild;
            BST temparent=T;//非递归实现时记录其父节点，对父节点的孩子指针进行修改即可
            while(temp->lchild){
                temparent=temp;//找到父节点
                temp=temp->lchild;
            }
            T->data=temp->data;
            if(temparent->lchild==temp){//非递归实现时修改父节点的孩子指针
                temparent->lchild=temp->rchild;
            }else if(temparent->rchild==temp){
                temparent->rchild=temp->rchild;
            }
//            BST_Delete(T->rchild,temp->data);//递归方式删除，不能传temp否则会造成其父节点的孩子指针变为野指针，效率较低
        }
    }
}

//测试用例 4 2 6 1 3 5 7 9999

int main(){
    BST T=NULL;
    Creat_BST(T);
    Inorder(T);
    printf("\n");
    BST search= Search(T,2);
    if(search) {
        printf("find %d\n", search->data);
    }else{
        printf("not find\n");
    }
    BST_Delete(T,6);
    Inorder(T);
    return 0;
}
