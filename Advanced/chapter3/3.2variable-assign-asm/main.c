#include <stdio.h>
//整型，整型数组，整型指针变量的汇编练习
int main() {
    int arr[3]={1,2,3};
    int *p;
    int i=5;
    int j=10;
    i=arr[2];
    p=arr;
    printf("i=%d\n",i);
    return 0;
}
