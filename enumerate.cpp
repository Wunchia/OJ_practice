#define _CRT_SECURE_NO_WARNINGS
#include "enumerate.h"
using namespace std;

//abc
//描述
//设a、b、c均是0到9之间的数字，abc、bcc是两个三位数，且有：abc+bcc=532。求满足条件的所有a、b、c的值。
//输入描述：
//题目没有任何输入。
//输出描述：
//请输出所有满足题目条件的a、b、c的值。 a、b、c之间用空格隔开。 每个输出占一行。

void abc(){
    int a,b,c;
    for(a=0;a<=9;++a){
        for(b=0;b<=9;++b){
            for(c=0;c<=9;++c){
                if(532==100*a+10*b+c+100*b+10*c+c){
                    printf("%d %d %d\n",a,b,c);
                }
            }
        }
    }
};

int main(){
    abc();
    return 0;
};

