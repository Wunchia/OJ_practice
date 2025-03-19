#include "func.h"

//函数定义
void print_message(){
    printf("how do you do\n");
    print_star(6);
}

int print_star(int i){
    printf("**********\n");
    printf("print_star %d\n",i);
    return i+3;
}