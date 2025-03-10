#include <stdio.h>

void change(char *c){
    *c='H';
    c[1]='E';
    *(c+2)='L';
}

int main(void) {
    char c[10]="hello";
    change(c);
    puts(c);
    return 0;
}
