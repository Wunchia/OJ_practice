#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    int size;//size代表要申请空间的大小
    char *p;//void*类型的指针无法偏移，因此往往不会定义无类型指针
    scanf("%d",&size);//如果输入20 则申请20字节空间

    //malloc返回的void*代表无类型指针 用(char*)进行强制类型转换
    p=(char*)malloc(size);
    strcpy(p,"malloc success");
    puts(p);

    free(p);//释放申请的空间 必须使用malloc返回给我们的地址 不能改变
    printf("free success");
    return 0;
}
//栈由操作系统管理 有底层寄存器配合
//而堆则是使用c/c++函数库提供的数据结构 通过算法在堆内存中搜索空闲空间
//如果碎片太多没有空间还需要通过系统调用去增加程序数据段的内存空间
//因此堆的效率比栈的效率要低得多