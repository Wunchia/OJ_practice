#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int ElemType;
typedef struct{
    ElemType *elem;
    int len;
}SSTable;

void RandomPutin(SSTable &ST,int len){
    int i;
    srand(time(NULL));
    for(i=0;i<len;i++){
        ST.elem[i]=rand()%100;
    }
}

void ScanfPutin(SSTable &ST,int len){
    int i,a;
    for(i=0;i<len;i++){
        scanf("%d",&a);
        ST.elem[i]=a;
    }
}

void ST_Init(SSTable &ST,int len){
    ST.len=len;
    ST.elem=(ElemType*) calloc(len,sizeof(ElemType));
    RandomPutin(ST,len);
//    ScanfPutin(ST,len);
}

void ST_Print(SSTable ST){
    for(int i=0;i<10;i++){
        printf("%3d",ST.elem[i]);
    }
    printf("\n");
}

void Swap(ElemType &a,ElemType &b){
    ElemType temp;
    temp=a;
    a=b;
    b=temp;
}

void AdjustDown(ElemType *A,int rootpos,int len){
    int parent=rootpos;
    int cur=2*parent+1;//左孩子的下标
    while(cur<len){
        if(cur+1<len&&A[cur]<A[cur+1]){
            cur++;
        }
        if(A[cur]>A[parent]) {
            Swap(A[cur], A[parent]);//如果孩子大于双亲，则交换
            parent = cur;//继续向下调整子树
            cur=2*parent+1;
        }else{
            break;
        }
    }
}

void HeapSort(ElemType *A,int len){
    int i;
    //将前十个元素调整为大根堆
    for(i=len/2-1;i>=0;i--){//从最后一个非叶节点开始
        AdjustDown(A,i,len);
    }
    //遍历剩余部分，收入最小十个元素
    for(i=10;i<100000;i++){
        if(A[i]<A[0]){
            A[0]=A[i];
            AdjustDown(A,0,10);
        }
    }
}

int main(){
    SSTable ST;
    ST_Init(ST,100000);
    ST_Print(ST);
    HeapSort(ST.elem,10);
    ST_Print(ST);
    return 0;
}