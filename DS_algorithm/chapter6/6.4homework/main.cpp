//读取10个整型数据12 63 58 95 41 35 65  0 38 44，
// 然后通过选择排序，堆排序，分别对该组数据进行排序，
// 输出2次有序结果，每个数的输出占3个空格
//=======================================================================
//读取10个整型数据12 63 58 95 41 35 65  0 38 44，
// 然后通过归并排序，对该组数据进行排序，输出有序结果，每个数的输出占3个空格

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10
typedef int ElemType;
typedef struct{
    ElemType *elem;
    int len;
}STable;

void ST_Init(STable &S,int len){
    S.len=len;
    S.elem=(ElemType*)calloc(S.len,sizeof(ElemType));
    ElemType a;
    for(int i=0;i<S.len;i++){
        scanf("%d",&a);
        S.elem[i]=a;
    }
}

void ST_Print(STable S){
    for(int i=0;i<S.len;i++){
        printf("%3d",S.elem[i]);
    }
    printf("\n");
}

void Swap(ElemType &a,ElemType &b){
    ElemType temp;
    temp=a;
    a=b;
    b=temp;
}

void SelectSort(STable &S){
    int i,j,min;
    for(i=0;i<S.len-1;i++){
        min=i;
        for(j=i+1;j<S.len;j++){
            if(S.elem[j]<S.elem[min]){
                min=j;
            }
        }
        if(i!=min){
            Swap(S.elem[i],S.elem[min]);
        }
    }
}

void AdjustDown(STable &S,int rootpos,int len){
    int parent=rootpos;
    int cur=parent*2+1;
    while(cur<len){
        if(cur+1<len&&S.elem[cur]<S.elem[cur+1]){
            cur++;
        }
        if(S.elem[cur]>S.elem[parent]) {
            Swap(S.elem[cur], S.elem[parent]);
            parent = cur;
            cur = parent * 2 + 1;
        }else{
            break;
        }
    }
}

void HeapSort(STable &S){
    int parent=S.len/2-1;
    int len=S.len;
    while(parent>=0){
        AdjustDown(S,parent,len);
        parent--;
    }
    while(len>1){
        Swap(S.elem[0],S.elem[--len]);
        AdjustDown(S,0,len);
    }
}

void Merge(ElemType *A,int low,int mid,int high){
    int i,j,k;
    static ElemType B[N];//static易漏
    for(i=0;i<=high;i++){
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
    if(low<high) {
        int mid = (low + high) / 2;
        MergeSort(A, low, mid);
        MergeSort(A, mid + 1, high);
        Merge(A, low, mid, high);
    }
}

int main(){
    STable S;
    ST_Init(S,10);
    ST_Print(S);
    int temp[S.len];
    memcpy(temp,S.elem,sizeof(temp));
    SelectSort(S);
    ST_Print(S);
    memcpy(S.elem,temp,sizeof(temp));
    HeapSort(S);
    ST_Print(S);
    memcpy(S.elem,temp,sizeof(temp));
    MergeSort(S.elem,0,S.len-1);
    ST_Print(S);
    free(S.elem);
    return 0;
}