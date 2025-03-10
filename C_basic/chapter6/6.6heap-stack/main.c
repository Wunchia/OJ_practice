#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* print_stack(){
    char c[100]="I am print_stack here";
    puts(c);
    return c;
}

char* print_malloc(){
    char *d=(char*)malloc(100);//堆空间在整个进程中有效，不因为函数结束而消亡
    strcpy(d,"I am print_malloc here");
    puts(d);
    return d;
}


int main(void) {
    char *p;
    p=print_stack();
    puts(p);//print_stack()的栈空间已被释放 p所指的c所在空间已被释放 无法正确打印

    p=print_malloc();
    puts(p);
    free(p);
    return 0;
}
