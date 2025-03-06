#include <stdio.h>

int main(void) {
    int i;
    char c;
    scanf("%d",&i);//输入 10\n 后只会从缓冲区读走10 残留\n
    printf("i=%d\n",i);//打印 10

//    //清空标准缓冲区 否则下一个scanf会读到上一个残留的\n
//    fflush(stdin);
//    //如未清空缓冲区 会直接读到残留的 \n 直接执行下一步printf
//    scanf("%c",&c);//读取char时不会忽略\n和空格 因为这两个也是char型
//    //如未清空缓冲区 则打印出 c=\n 这里 \n 体现为换行 加上printf中的\n 会换行两次
//    printf("c=%c\n",c);

    //scanf在读取整型数、浮点数、字符串的时候会忽略 \n 和 空格
    float f;
    scanf("%f",&f);
    printf("f=%f\n",f);

    //scanf一次读多种数据类型
    int ret;
    //%c前加空格可以避免%c读到用于间隔输入时输入的空格
    ret=scanf("%d %c%f",&i,&c,&f);//ret时scanf匹配成功的个数
    printf("i=%d,c=%c,f=%f",i,c,f);

    return 0;
}
