#include <stdio.h>
#include <string.h>
int main(){
    char c[100];
    char d[100]={0};
    gets(c);
    int len=strlen(c);
    for(int i=0,j=len-1;i<len;i++,j--){
        d[i]=c[j];
    }
    int result = strcmp(c, d);
    if(result < 0){
        printf("%d\n",-1);
    }else if(result > 0){
        printf("%d\n", 1);
    }else{
        printf("%d\n", 0);
    }
    return 0;
}

//读取一个字符串，字符串可能含有空格，将字符串逆转，原来的字符串与逆转后字符串相同，输出0，
// 原字符串小于逆转后字符串输出-1，大于逆转后字符串输出1。
// 例如输入 hello，逆转后的字符串为 olleh，因为hello 小于 olleh，所以输出-1
//注意最后的判断一定要这么写，因为strcmp标准C中并不是返回-1和1，而是负值和正值
//int result = strcmp(c, d);
//if (result < 0){
//printf("%d\n",-1);
//}else if (result > 0){
//printf("%d\n", 1);
//}else {
//printf("%d\n", 0);
//}



//int main(void) {
//    int i,count=0;
//    int a[100];
//    scanf("%d",&i);
//    for(int j=0;j<i;j++){
//        scanf("%d",&a[j]);
//    }
//    for(int k=0;k<i;k++){
//        if(2==a[k]){
//            count++;
//        }
//    }
//    printf("%d\n",count);
//    return 0;
//}

//输入N个数（N小于等于100），输出数字2的出现次数；
//解题提示：
//整型数组读取5个整型数的方法如下：
//int a[100];
//for(int i=0;i<5;i++)
//{
//scanf("%d",&a[i]);
//}