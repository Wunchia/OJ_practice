#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

int BinarySearch(SSTable ST,ElemType key){
    int low=1;
    int high=ST.TableLen;
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(key>ST.elem[mid]){
            low=mid+1;
        }else if(key<ST.elem[mid]){
            high=mid-1;
        }else{
            return mid;
        }
    }
    return -1;
}

//函数名中存储的是函数的入口地址，也是一个指针，是函数指针类型
//left指针和right指针指向数组中的任意两个元素
//qsort规定如果left指向的值大于right指向的值，则返回正值，小于返回负值，相等返回0;此时从小到大排序
int compare(const void *left,const void *right){
    return *(ElemType *)left-*(ElemType *)right;
    //return *(ElemType*)right-*(ElemType*)left;//从大到小排序
}

int main(){
    SSTable ST;
    ElemType key;
    ST_Init(ST,10);
    ST_Print(ST);
    qsort(ST.elem+1,ST.TableLen-1,sizeof(ElemType),compare);
    ST_Print(ST);
    printf("choose the search key\n");
    scanf("%d",&key);
    int pos= BinarySearch(ST,key);
    if(pos!=-1){
        printf("key: %d is at the pos of %d\n",key,pos);
    }else{
        printf("not find\n");
    }
    return 0;
}