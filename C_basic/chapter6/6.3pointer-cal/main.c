#include <stdio.h>
#define N 5
int main(void) {
    int a[N]={1,2,3,4,5};
    int *p;
    p=a;
    int i;
    for(i=0;i<N;i++){
        printf("%3d",*(p+i));//p是数组起始位置指向a[0],*p+i等价于a[i]
    }
    printf("\n");
    p=&a[4];
    for(i=0;i<N;i++){
        printf("%3d",*(p-i));//p指向a[4],*p-i等价于a[4-i]
    }
    printf("\n");
    return 0;
}
