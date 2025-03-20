#include <stdio.h>

void modify_num(int &c,int d){
    c=c+1;
    d=d+1;
    printf("in modify b=%d\n",d);
}

void modify_pointer(int *&p,int *q){//引用必须和变量名紧邻
    p=q;
    int j=10086;
//    *q=j;//p、q都会变为10086，因为都指向i，而i通过q被修改为10086
    q=&j;//q未通过引用传入，不会被带回
    printf("in modify *p=%d,*q=%d\n",*p,*q);
}

int main(){
    int a=10;
    int b=10;
    modify_num(a,b);
    printf("after modify a=%d b=%d\n",a,b);
    printf("-----------------\n");
    int *p=NULL;
    int i=10;
    int *q=&i;
    modify_pointer(p,q);
    printf("after modify *p=%d,*q=%d,i=%d\n",*p,*q,i);

    return 0;
}