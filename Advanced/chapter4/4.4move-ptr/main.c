#include <stdio.h>
#include <string.h>
int main() {
    //fseek(文件类型指针，位移量，起始点）
    //long ftell(FILE *stream);返回流当前的文件位置（相对于文件开头的位置）
    FILE *fp;
    char str[20]="hello\nworld";
    int len=0;
    long pos;
    int ret;
    //打开文件
    fp=fopen("file.txt","r+");
    if(NULL==fp){
        perror("fopen");
        return -1;
    }
    //写入字符串
    len=strlen(str);
    ret=fwrite(str,sizeof(char),len,fp);

    //找到当前光标位置
    pos=ftell(fp);
    printf("Now pos=%ld\n",pos);

    //移动光标位置
    ret=fseek(fp,-5,SEEK_CUR);
    if(ret!=0){
        perror("fseek");
        fclose(fp);
        return -1;
    }

    //找到当前光标位置
    pos=ftell(fp);
    printf("Now pos=%ld\n",pos);

    //读出内容
    memset(str,0,sizeof(str));//把str清空
    ret=fread(str,sizeof(char),sizeof(str),fp);
    if(EOF==ret){
        perror("fread");
        return -1;
    }
    printf("%s\n",str);
    //关闭文件
    fclose(fp);
    return 0;
}
