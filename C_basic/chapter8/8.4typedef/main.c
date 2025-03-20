#include <stdio.h>

typedef struct student{
    int num;
    char name[20];
    char sex;
}stu,*pstu;

typedef int INTEGER;//特定地方使用，方便统一修改类型

int main(void) {
    stu s={0};
    pstu p=&s;

    INTEGER i=10;

    printf("%d\n",i);

    printf("%d\n",sizeof(s));
    printf("%d\n",sizeof(p));
    return 0;
}
