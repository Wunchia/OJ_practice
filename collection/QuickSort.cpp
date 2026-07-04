#include <algorithm>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

typedef int ElemType;

//============= 准备数据结构 ===============
typedef struct{
    ElemType *elem;
    int TableLen;
}SSTable;

void ST_Init(SSTable &ST,int len){
    ST.TableLen=len+1;//第0个位置放置哨兵
    ST.elem=(ElemType*)malloc(sizeof(ElemType)*ST.TableLen);
    srand(time(NULL));//生成随机数种子
    for(int i=1;i<ST.TableLen;++i){
        ST.elem[i]=rand()%100;//生成0-99之间的随机数
    }
}

//============ 工具函数 ===============
void ST_Print(SSTable ST){
    for(int i=1;i<ST.TableLen;++i){
        printf("%3d",ST.elem[i]);
    }
    printf("\n");
}

//===============快排算法===============
int Partition(ElemType *A,int low,int high){
    ElemType pivot=A[low];//选中第一个元素为枢轴
    while(low<high){
        while(low<high&&A[high]>pivot){
            high--;
        }
        A[low]=A[high];//把小于枢轴的放到枢轴左边
        while(low<high&&A[low]<=pivot){
            low++;
        }
        A[high]=A[low];//把大于枢轴的放到枢轴右边
    }
    A[low]=pivot;//此时low和high都指向枢轴位置
    return low;
}

void QuickSort(ElemType *A,int low,int high){
    if(low<high){
        int pivotpos=Partition(A,low,high);
        QuickSort(A, low, pivotpos-1);//继续划分左半
        QuickSort(A, pivotpos+1, high);//继续划分右半
    }
}


int main(int argc,char *argv[])
{
    SSTable ST;
    ST_Init(ST, 10);
    ST_Print(ST);
    QuickSort(ST.elem, 1, 10);
    ST_Print(ST);
    free(ST.elem);
    return 0;
}
