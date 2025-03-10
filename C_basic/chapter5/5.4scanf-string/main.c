#include <stdio.h>
//scanf读取字符串，会自动往字符数组中放结束符
int main(void) {
    char c[10];
    char d[10];
    scanf("%s%s",c,d);//字符数组名中存储了数组起始地址 因此不需&取地址
    printf("c=%s,d=%s\n",c,d);

    return 0;
}
