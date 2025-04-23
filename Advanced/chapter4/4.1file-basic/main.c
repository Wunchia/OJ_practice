#include <stdio.h>
//在stdio.h中的定义：
//struct _iobuf {
//    char *_ptr; //下一个要被读取的字符地址
//    int _cnt; //缓冲区中剩余的字符数
//    char *_base; //缓冲区基地址，指向为该流分配的缓冲区的起始地址
//    int _flag; //状态标志位（例如，读/写，错误，文件结束等）
//    int _file; //文件描述符 打开文件的唯一标识 操作系统内核通过文件描述符来区分打开的不同文件
//    int _charbuf; //用于单字符缓冲的字符（通常在没有完整缓冲区时使用）
//    int _bufsiz; //缓冲区大小
//    char *_tmpfname;  // 指向临时文件名的指针（如果该流与临时文件关联）
//};
//typedef struct _iobuf FILE; //别名 FILE

int main() {
    FILE *fp;
    fp=fopen("file.txt","r+");
    if(NULL==fp){
        perror("fopen failed");//perror帮助定位失败原因
        return -1;
    }
    char c;
    while( (c=fgetc(fp))!=EOF) {
        printf("%c", c);
    }
    printf("\n");
    c=fputc('H',fp);
    if(-1==c){
        perror("fputc");
        return -1;
    }
    fclose(fp);
    return 0;
}
