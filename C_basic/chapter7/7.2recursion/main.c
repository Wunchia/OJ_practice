#include <stdio.h>

int recursion(int i){
    if(i==1) {
        return 1;
    }
    return i*recursion(i-1);
}

int step(int n){
    if(n==1||n==2){
        return n;
    }
    return step(n-1)+step(n-2);
}


int main(void) {
//    int n;
//    scanf("%d",&n);
//    printf("f(%d)=%d",n,recursion(n));
//    return 0;

//有n个台阶，一次只能上一个或两个台阶，走到第n个台阶一共有几种走法
    int a;
    scanf("%d",&a);
    printf("%d",step(a));
    return 0;
}
