#include <stdio.h>

int main(void) {
    int a=1,b=2;
    //a+25=b;//常量不能做左值
    b=a+25;
    a=a+1;
    a*=5;
    b+=5;
    printf("a=%d,b=%d",a,b);
    return 0;
}
