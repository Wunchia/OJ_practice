#include <stdio.h>
#include <stdlib.h>
int main(){
    int size;
    scanf("%d",&size);
    char* p=(char*)malloc(size);
    char c;
    scanf("%c",&c);//清除缓冲区残留的\n
    fgets(p,size,stdin);
    puts(p);
    return 0;
}


//输入一个整型数，然后申请对应大小空间内存，然后读取一个字符串（测试用例的字符串中含有空格），
//字符串的输入长度小于最初输入的整型数大小，最后输出输入的字符串即可（无需考虑输入的字符串过长，超过了内存大小）；
//注意下面问题：
//char *p;
//scanf("%d",&n);
//p=malloc(n);
//scanf("%c",&c);//注意在scanf和gets中间使用scanf("%c",&c),去除换行
//fgets(p,n,stdin);
//注意：OJ不支持fflush(stdin)清空标准输入缓冲区操作。
//OJ不支持gets，因为C11标准去掉了，部分学校机试可以用gets，部分不可以，因此建议使用fgets





//void change(int *i){
//    *i=*i/2;
//}
//
//int main(void) {
//    int i;
//    scanf("%d",&i);
//    change(&i);
//    printf("%d",i);
//    return 0;
//}
//输入一个整型数，存入变量i，通过子函数change把主函数的变量i除2，然后打印i，例如如果输入的为10，打印出5，如果输入的为7，打印出3