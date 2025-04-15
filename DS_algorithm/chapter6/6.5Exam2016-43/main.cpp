#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;

void printf(ElemType *A,int len){
    for(int i=0;i<len;i++){
        printf("%3d",A[i]);
    }
    printf("\n");
}

int setPartition(ElemType *A,int len){
    int pivot,flag=1,low=0,high=len-1,mid=len/2;
    int low0=0,high0=len-1;//限制待分区间
    int s1=0,s2=0;
    while(flag) {
        int pivot=A[low];
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
        if(low==mid-1) {
            flag = 0;
        }else{
            if(low<mid-1){//左短右长
                low0=low++;//记录low0，排除左侧已确定位置的部分
                high=high0;//重置右端点
            }else{//左长右短
                high0=low--;//记录high0，排除右侧已确定位置的部分
                low=low0;//重置左端点
            }
        }
    }
    for(int i=0;i<mid;i++){
        s1+=A[i];
    }
    for(int i=mid;i<len;i++){
        s2+=A[i];
    }
    return s2-s1;
}

int main(){
    ElemType A[10]={4,1,12,18,7,13,18,16,2,15};
//    int a;
//    for(int i=0;i<10;i++){
//        scanf("%d",&a);
//        A[i]=a;
//    }
    int diff;
    diff=setPartition(A,10);
    printf("%d\n",diff);
    printf(A,10);

}