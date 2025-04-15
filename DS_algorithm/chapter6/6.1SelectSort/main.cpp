#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int ElemType;
typedef struct{
    ElemType *elem;
    int len;
}SSTable;

void ST_Init(SSTable &ST,int len){
    ST.len=len;
    ST.elem=(ElemType*) calloc(len,sizeof(ElemType));
    int i;
    srand(time(NULL));
    for(i=0;i<len;i++){
        ST.elem[i]=rand()%100;
    }
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

void SelectSort(ElemType *A,int len){
    int i,j,min;
    for(i=0;i<len-1;i++){
        min=i;
        for(j=i+1;j<len;j++){
            if(A[j]<A[min]){
                min=j;
            }
        }
        Swap(A[i],A[min]);
    }
}

int main(){
    SSTable ST;
    ST_Init(ST,10);
    ST_Print(ST);
    SelectSort(ST.elem,ST.len);
    ST_Print(ST);
    return 0;
}