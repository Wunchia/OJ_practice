//读取10个整型数据12 63 58 95 41 35 65  0 38 44，
//然后通过冒泡排序，快速排序，插入排序，分别对该组数据进行排序
//输出3次有序结果，每个数的输出占3个空格

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int ElemType;

typedef struct{
    ElemType *elem;
    int len;
}SStable;

void Init_ST(SStable &ST,int len){
    ST.len=len;
    ST.elem=(ElemType*) calloc(len,sizeof(ElemType));
}

void Print_ST(SStable ST){
    for(int i=0;i<ST.len;i++){
        printf("%3d",ST.elem[i]);
    }
    printf("\n");
}

void  Swap(ElemType &a,ElemType &b){
    ElemType temp;
    temp=a;
    a=b;
    b=temp;
}

void BubbleSort(ElemType *A,int len){
    int i,j;
    bool flag;
    for(i=0;i<len-1;i++){
        flag=false;
        for(j=len-1;j>i;j--){
            if(A[j]<A[j-1]){
                Swap(A[j],A[j-1]);
                flag=true;
            }
        }
        if(false==flag){
            return;
        }
    }
}

int partition(ElemType *A,int low,int high){
    ElemType pivot=A[low];
    while(low<high) {
        while (low<high&&A[high] > pivot) {
            high--;
        }
        A[low] = A[high];
        while (low<high&&A[low] <= pivot) {
            low++;
        }
        A[high] = A[low];
    }
    A[low]=pivot;
    return low;
}

void QuickSort(ElemType *A,int low,int high){
    if(low<high) {
        int pivotpos = partition(A, low, high);
        QuickSort(A,low,pivotpos-1);
        QuickSort(A,pivotpos+1,high);
    }
}

void InsertSort(ElemType *A,int len){
    ElemType insertval;
    int i,j;
    for(i=0;i<len;i++){
        insertval=A[i];
        for(j=i-1;j>=0&&A[j]>insertval;j--){
            A[j+1]=A[j];
        }
        A[j+1]=insertval;
    }
}

int main(){
    SStable ST;
    Init_ST(ST,10);
    int i=0;
    ElemType a;
    ElemType A[10];
    while(i<10){
        scanf("%d",&a);
        A[i]=a;
        i++;
    }
    memcpy(ST.elem,A,sizeof(A));
    BubbleSort(ST.elem,ST.len);
    Print_ST(ST);
    memcpy(ST.elem,A,sizeof(A));
    QuickSort(ST.elem,0,ST.len-1);
    Print_ST(ST);
    memcpy(ST.elem,A,sizeof(A));
    InsertSort(ST.elem,ST.len);
    Print_ST(ST);
    return 0;
}