#include <stdio.h>

//短路运算 逻辑与和逻辑或

int main(void) {
    int i=1;
    i&&printf("you can't see me &&\n");//当i为假时，不会执行&&后面的运算，看不到打印；为真时可看到打印
    i=0;
    i||printf("you can't see me ||\n");//当i为真时，不会执行||后面的运算，看不到打印；为假时可看到打印
    return 0;
}
