#include <stdio.h>

//模拟printf("%s",c)操作
void print(char d[]){
    int i=0;
    while(d[i]){
        printf("%c",d[i]);
        i++;
    }
    printf("\n");
}

int main(void) {
    char c[10]={'I','a','m',' ','h','a','p','p','y'};
    char d[11]="I am happy";//最后会多一个结束符\0
    printf("%s\n",c);
    printf("%s\n",d);//如果输出乱码，可以检查字符数组长度是否不够，导致没有\0
    print(c);
    return 0;
}
