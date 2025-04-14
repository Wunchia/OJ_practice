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

void InsertSort(ElemType *A,int len){
    int i,j,insertval;
    for(i=1;i<len;i++){
        insertval=A[i];
        for(j=i-1;j>0&&A[j]>insertval;j--){
            A[j+1]=A[j];
        }
        A[j+1]=insertval;
    }
}

int main(){
    SSTable ST;
    ST_Init(ST,10);
    ST_Print(ST);
    InsertSort(ST.elem,ST.TableLen);
    ST_Print(ST);
    return 0;
}