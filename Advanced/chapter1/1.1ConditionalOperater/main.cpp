#include <stdio.h>

int main(){
    //三目运算符
    int a,b,max;
    while(scanf("%d%d",&a,&b)){
        max=a>b?a:b;
        printf("max=%d\n",max);
    }
    //逗号运算符
    int i=1,j=1;
    if(i-1,j){
        printf("%d\n",j);
    }
    return 0;
}