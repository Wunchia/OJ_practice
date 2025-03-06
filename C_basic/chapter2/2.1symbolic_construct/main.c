#include <stdio.h>
//symbolic_construct

#define PI 3+2//PI是整型常量
#define minf 3e-10//minf是浮点型常量

int main() {
    //整型
    int i=PI*2;//i是整型变量
    printf("i=%d\n",i);//常量会直接替换 输出3+2*2=7
    printf("i size=%d\n",sizeof(i));//size 4byte

    //浮点型
    float f=3e-3;
    printf("f=%d\n",f);
    printf("minf=%d\n",minf);

    //char型
    char c='A';
    printf("%c\n",c+32);
    printf("%d\n",c);
    printf("%d\n",c+32);

    //字符串常量
    printf("how are you\n");

    return 0;
}
