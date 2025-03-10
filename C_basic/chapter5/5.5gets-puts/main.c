#include <stdio.h>
#include <string.h>

int mystrlen(char c[]){
    int i=0;
    while(c[i]){
        i++;
    }
    return i;
}

int main(void) {
    int len;
    char c[20];
    char d[100]="world";
    char e[100];
    gets(c);//一次输入一整行 空格也读 读到\n停止 末尾添加结束符\0
    puts(c);//等价于printf("%s\n",c); puts内的参数只能放字符数组名

    //str系列字符串操作函数
    len=strlen(c);
    printf("len=%d\n",len);
    len=mystrlen(c);
    printf("my len=%d\n",len);

    strcat(c,d);
    printf("%s\n",c);

    strcpy(e,c);
    printf("%s\n",e);

    //strcmp比较的是字符串的ASCII码大小 c>"how 返回正值
    printf("c?d=%d\n",strcmp(c,"how"));

    return 0;
}
