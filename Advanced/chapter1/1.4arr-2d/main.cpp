#include <stdio.h>

int main() {
    int a[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
    printf("sizeof(a)=%d\n",sizeof(a));
    printf("a[2][3]=%d\n",a[2][3]);
    int i=10;
    int *p=&i;
    int **p2=&p;
    printf("sizeof(p2)=%d\n",sizeof(p2));
    printf("**p2=%d\n",**p2);
    return 0;
}
