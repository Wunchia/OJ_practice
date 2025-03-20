#include <stdio.h>
#include <string.h>
struct student{
    int num;
    char name[20];
    char sex;
    int age;
    float score;
};

int main(void) {
    struct student s1={1001,"jane",'W',20,85.4};
    struct student sarr[3];
    struct student s2;
    s2.num=1002;
    strcpy(s2.name,"jack");
    s2.sex='M';
    s2.age=26;
    s2.score=84.3;

    printf("%d %s %c %d %f\n",s1.num,s1.name,s1.sex,s1.age,s1.score);
    sarr[0]=s1;
    sarr[1]=s2;
    scanf("%d%s %c%d%f",&sarr[2].num,sarr[2].name,&sarr[2].sex,&sarr[2].age,&sarr[2].score);
    printf("%d %s %c %d %f\n",s1.num,s1.name,s1.sex,s1.age,s1.score);
    printf("%d %s %c %d %f\n",s2.num,s2.name,s2.sex,s2.age,s2.score);
    printf("%d %s %c %d %f\n",sarr[2].num,sarr[2].name,sarr[2].sex,sarr[2].age,sarr[2].score);
    return 0;
}
