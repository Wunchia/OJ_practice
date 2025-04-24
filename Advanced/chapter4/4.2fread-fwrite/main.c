#include <stdio.h>
#include <string.h>
int main() {
    char buf[20]="hello\nworld";
    FILE *fp;
    int i=123456;
    int ret;
    fp=fopen("file.txt","rb+");//r+以文本方式打开文件，rb+以二进制方式打开
//    fp=fopen("file.txt","wb+");//如果不存在对应文件，wb+会新建文件；已存在会删除该文件重新新建一个空文件
    //=================================
    //文本方式打开在windows系统下会将\n存储为\r\n，导致多一个字节
    //二进制方式打开 则\n就是\n，不会多一个字节
    //=================================
    if(NULL==fp){
        perror("fopen");
        return -1;
    }
//    ret=fwrite(buf,sizeof(char),strlen(buf),fp);//把buf中的字符串写入文件
//    char buf1[20]={0};
//    ret=fread(buf1,sizeof(char),sizeof(buf1),fp);
//    printf("%s\n",buf1);

//    ret=fwrite(&i,sizeof(int),1,fp);
    i=0;
    fread(&i,sizeof(int),1,fp);//写完以后光标在文件内容的末尾，将写的那一行注释掉后重新运行才能读到
    printf("i=%d\n",i);
    fclose(fp);
    return 0;
}
