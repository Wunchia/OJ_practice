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
    for(int i=0;i<ST.len;i++){
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
    //将堆调整为大根堆
    for(i=len/2-1;i>=0;i--){//从最后一个非叶节点开始
        AdjustDown(A,i,len);
    }
    //将堆顶的最大值换至数组末尾
    Swap(A[0],A[len-1]);
    //调整剩余部分
    for(i=len-1;i>1;i--){
        AdjustDown(A,0,i);//i是剩余无序部分的长度
        Swap(A[0],A[i-1]);
    }
}
//87 53 13 11 18 64 35 18 88 47
// 94 89 54 44 20 17 15 70  6 28
int main(){
    SSTable ST;
    ST_Init(ST,10);
    ST_Print(ST);
    HeapSort(ST.elem,ST.len);
    ST_Print(ST);
    return 0;
}