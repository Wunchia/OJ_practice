#include <stdio.h>
#include <stdlib.h>
#define N 7
typedef int ElemType;

void Print(ElemType *A,int len){
    for(int i=0;i<len;i++){
        printf("%3d",A[i]);
    }
    printf("\n");
}

void Merge(ElemType *A,int low,int mid,int high){
    static ElemType B[N];
    int i,j,k;
    for(i=low;i<=high;i++){//复制一份
        B[i]=A[i];
    }
    k=low;
    for(i=low,j=mid+1;i<=mid&&j<=high;k++){
        if(B[i]<B[j]){
            A[k]=B[i++];
        }else{
            A[k]=B[j++];
        }
    }
    while(i<=mid){
        A[k++]=B[i++];
    }
    while(j<=high){
        A[k++]=B[j++];
    }
}

void MergeSort(ElemType *A,int low,int high){
    if(low<high){
        int mid=(low+high)/2;//找到归并段的中间
        MergeSort(A,low,mid);//情况一：归并段内只有一个元素时跳过if返回
        MergeSort(A,mid+1,high);//情况二：下一层递归返回后，继续向后执行完Merge后返回
        Merge(A,low,mid,high);//将两个归并段归并
    }
}

int main(){
    int A[N]={49,38,65,97,76,13,27};
    Print(A,N);
    MergeSort(A,0,6);
    Print(A,N);
    return 0;
}