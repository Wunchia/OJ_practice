#include <stdio.h>

int main(void) {
    //数组定义
    int b[10];
    int c[]={1,2,3,4,5};
    int d[3]={0};
    

    //访问越界
    int a[5]={1,2,3,4,5,};
    int j=20;//0x5ffe8d
    int i=10;//0x5ffe88
    a[5]=6;//0x5ffe84 访问越界 但踩到的空间为空
    a[6]=7;//0x5ffe88 访问越界 踩到了i的内存空间
    printf("i=%d\n",i);//没有修改i的值 但i输出为7
    printf("a[5]=%d\n",a[5]);//输出为6 虽然访问越界 但赋值后有值存在

    return 0;
}
