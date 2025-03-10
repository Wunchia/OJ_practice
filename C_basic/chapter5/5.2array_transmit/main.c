#include <stdio.h>

void print(int a[],int len){
    int i;
    //数组传递到子函数中 子函数的形参接收到的是数组地址 所以sizeof(a)=8
    printf("sizeof(a)=%d\n",sizeof(a));
    for(i=0;i<len;i++){
        printf("%3d",a[i]);
    }
    a[3]=20;
    printf("\n");
}

int main(void) {
    int a[5]={1,2,3,4,5};
    print(a,5);
    printf("a[3]=%d\n",a[3]);
    return 0;
}
