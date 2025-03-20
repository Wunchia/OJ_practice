#include <stdio.h>

struct student_type1{
    double score;//8
    int height;//4
    short age;//2
};

struct student_type2{
    int height;//4
    char sex;//1
    short age;//2
};

int main(void) {
    struct student_type1 s1={1,2,3};
    struct student_type2 s2={1,'a',2};
    printf("s1 size=%u\n",sizeof(s1));
    printf("s1 size=%u\n",sizeof(s2));

    return 0;
}
