#include <stdio.h>

int main(void) {
    int i=123;//二进制 0111 1011 八进制 173 十六进制 7b 00 00 00
//    int i=0173;//用八进制赋值
//    int i=0x7b;//用十六进制赋值
    printf("%d\n",i);//十进制 123
    printf("%o\n",i);//八进制 173
    printf("%x\n",i);//十六进制 7b 00 00 00 小端存储 ； 00 00 00 7b 大端存储
    return 0;
}
