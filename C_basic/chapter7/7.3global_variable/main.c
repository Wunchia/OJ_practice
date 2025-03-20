#include <stdio.h>

int i=10;//定义在数据段

void print(int a){//形参看成一个局部变量
    printf("i am print i=%d\n",a);
}

void global_i(){
    printf("i am global i=%d\n",i);
}

int main(void) {
    int i=3;//定义在栈空间
    {
        int j=11;
    }
    printf("main i=%d\n",i);
//    printf("main j=%d\n",j);//局部变量只在离自己最近的大括号内有效
    print(5);
    global_i();
    return 0;
}
