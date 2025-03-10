#include <stdio.h>

int main(void) {
    //算术运算符
    int result=4+5*2-6/3+11%4; //模运算取余数 4+10-2+3=15
    printf("result=%d",result);

    //关系运算符 优先级小于算术运算符
//    int i;
//    while(scanf("%d",&i)){
//        if(3<i<10){ //错误写法，3<a判断后要么为0，要么为1；所以<10恒为真
//            printf("i is between 3 and 10\n");
//        }else{
//            printf("i is not between 3 and 10\n");//这一句永远不会得到执行
//        }
//    }

    int a;
    while(scanf("%d",&a)){
        if(3<a && a<10){ //正确写法
            printf("a is between 3 and 10\n");
        }else{
            printf("a is not between 3 and 10\n");
        }
    }
    return 0;
}
