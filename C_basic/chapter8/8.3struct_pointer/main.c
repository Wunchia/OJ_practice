#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//结构体指针
struct student{
    int num;
    char name[20];
    char sex;
};

int main(void) {
    struct student s={1001,"name",'M'};
    struct student sarr[3]={1002,"jack",'M',1003,"amy",'W',1004,"kevin",'M'};
    struct student *p;
    p=&s;
    printf("%d %s %c\n",(*p).num,p->name,p->sex);//两种方式通过结构体指针访问成员
    p=&sarr;//等价于p=&sarr[0];
    printf("%d %s %c\n",(*p).num,p->name,p->sex);
    p=p+2;
    printf("%d %s %c\n",(*p).num,p->name,p->sex);

    //通过malloc申请空间，并赋值打印
    p=(struct student*)malloc(sizeof(struct student));
    p->num=100;
    p->sex='M';
    strcpy(p->name,"raj");

    printf("%d %s %c\n",(*p).num,p->name,p->sex);
    printf("size of p=%d\nsize of *p=%d\n",sizeof(p),sizeof(*p));

    return 0;
}
