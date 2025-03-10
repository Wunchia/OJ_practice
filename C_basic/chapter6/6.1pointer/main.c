#include <stdio.h>

int main(void) {
    int i=5;//4B
    char c='a';//1B
    int *ip=&i;//8B
    char *cp;//8B
    cp=&c;
    printf("i=%d\n",i);
    *ip=10;//间接访问
    printf("i=%d\n",i);
    printf("i loc=%x\n",ip);

    return 0;
}
