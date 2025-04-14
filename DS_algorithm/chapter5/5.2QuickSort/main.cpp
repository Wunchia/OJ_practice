#include  <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef int ElemType;

typedef struct{
    ElemType *elem;
    int TableLen;
}SSTable;

void ST_Init(SSTable &ST,int len){
    ST.TableLen=len+1;//第0个位置放哨兵
    ST.elem=(ElemType*)malloc(sizeof(ElemType)*ST.TableLen);
    srand(time(NULL));//随机数生成
    for(int i=1;i<ST.TableLen;i++){
        ST.elem[i]=rand()%100;//为了随机数都在0-99之间
    }
}

void ST_Print(SSTable ST){
    for(int i=1;i<ST.TableLen;i++){
        printf("%3d",ST.elem[i]);
    }
    printf("\n");
}

void Swap(int &a,int &b){
    int tmp;
    tmp=a;
    a=b;
    b=tmp;
}

int Partition(ElemType *A,int low,int high){
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
        int pivotpos = Partition(A, low, high);
        QuickSort(A, low, pivotpos - 1);
        QuickSort(A, pivotpos + 1, high);
    }
}

int main(){
    SSTable ST;
    ST_Init(ST,10);
    ST_Print(ST);
    QuickSort(ST.elem,1,10);
    ST_Print(ST);
    return 0;
}