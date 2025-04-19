#include <stdio.h>

int main() {
    int a;//4B
    short b;//2B -32768~32767 ; 1000 0000 0000 0000-> -32768
    long c;//4B 32位机器 8B 64位机器
    unsigned int d;//4B
    unsigned short e;//2B 0~65535
    unsigned long f;//4B 32位机器 8B 64位机器
    a=10;
    b=32767;
    short overflow=0;
    overflow=b+1;
    printf("%d\n",overflow);
    return 0;
}
