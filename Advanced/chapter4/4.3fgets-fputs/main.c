#include <stdio.h>

int main() {
    char buf[20]={0};
    FILE *fp;
    int ret;
    fp= fopen("file.txt","r+");
    if(NULL==fp){
        perror("fopen");
    }
    //一次读一行，读空文件
    while(fgets(buf,sizeof(buf),fp)!=NULL) {//将fp里的sizeof(buf)大小的内容放到buf中
        printf("%s", buf);
    }

    while(fgets(buf,sizeof(buf),stdin)!=NULL) {//将stdin和scanf的区别在于，stdin会将输入缓冲区的\n一并读入
        printf("%s", buf);//而scanf只会读入\n之前的内容，\n会被留在输入缓冲区
    }
    return 0;
}
