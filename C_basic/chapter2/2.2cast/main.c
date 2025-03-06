#include <stdio.h>
//强制类型转换
int main() {
    int i=5;
    float f1=i/2;//这里做的是整型运算 因为左右操作数都是整型
    printf("%f\n",f1);//输出2
    float f2=(float)i/2;//强制类型转换
    printf("%f\n",f2);//输出2.5

    //printf练习
    //int printf(const char *format,...)
    //printf函数根据format给出的格式将内容输出到stdout和其他参数中
    int age=31;
    printf("%s is %d years old.\n","Bob",age);

    int num=10;
    float f=36.3;
    printf("student num=%-3d; score is %5.2f.\n",num,f);//d占三位。f占5位，小数点后保留两位
    num=100;
    f=39.45;
    printf("student num=%-3d; score is %5.2f.\n",num,f);//默认右对齐，加负号左对齐
    return 0;
}
