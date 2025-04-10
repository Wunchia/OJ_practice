#include <stdio.h>

//双数组二分查找
int MidSearch(int A[],int B[],int len){
    int s1=0,d1=len-1,s2=0,d2=len-1;
    int mid1,mid2;
    while(s1!=d1||s2!=d2){//两个数组均只剩下一个元素时
        mid1=(s1+d1)/2;
        mid2=(s2+d2)/2;
        if(A[mid1]<B[mid2]){//A中较小的一半在中位数左边，B中较大的一半在中位数右边
            if((s1+d1)%2==0){//游标中间夹着的元素个数为奇数个
                s1=mid1;
                d2=mid2;
            }else if((s1+d1)%2==1){//游标中间夹着的元素个数为偶数个
                s1=mid1+1;
                d2=mid2;
            }
        }else if(A[mid1>B[mid2]]){//B中较小的一半在中位数左边，A中较大的一半在中位数右边
            if((s1+d1)%2==0){//游标中间夹着的元素个数为奇数个
                d1=mid1;
                s2=mid2;
            }else if((s1+d1)%2==1){//游标中间夹着的元素个数为偶数个
                d1=mid1;
                s2=mid2+1;
            }
        }else{
            return A[mid1];
        }
    }
    if(A[s1]<B[s2]){
        return A[s1];
    }else{
        return B[s2];
    }
}


int Solution(int A[],int B[],int len){
    int a=0,b=0;
    while(len-1>0){
        if(A[a]<B[b]){
            a++;
        }else{
            b++;
        }
        len--;
    }
    if(A[a]<B[b]){
        return A[a];
    }else{
        return B[b];
    }
}

int main(){
    int A[]={11,13,15,17,19};
    int B[]={2,4,6,8,20};
    int mid1=MidSearch(A,B,5);
    int mid2= Solution(A,B,5);
    printf("solution1 mid=%d\n",mid1);
    printf("solution2 mid=%d\n",mid2);
    return 0;
}