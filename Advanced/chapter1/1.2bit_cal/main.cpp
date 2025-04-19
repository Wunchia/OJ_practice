#include <stdio.h>
#include <stdlib.h>
int main() {
    short i=5;
    short j;
    j=i<<1;//左移乘2
    printf("j=%d\n",j);
    i=-4;//右移除2；-1无论右移多少位都是-1
    j=i>>1;
    printf("j=%d\n",j);
    printf("-----------------------\n");
    i=0x8011;
    unsigned short s=0x8011;
    unsigned short r=0;
    j=i>>1;//有符号负数右移，前补1
    r=s>>1;//无符号数右移，前补0
    printf("j=%d,r=%u\n",j,r);
    printf("-------------------\n");
    i=5,j=7;//5 0000 0000 0000 0101  7  0000 0000 0000 0111
    printf("i&j=%d\n",i&j);//0101
    printf("i|j=%d\n",i|j);//0111
    printf("i^j=%d\n",i^j);//0010
    printf("~i=%d\n",~i);//1010->(-110)
    printf("-------------------------\n");
    //找出只出现过一次的数（出现过奇数次的数）
    int arr[5]={8,5,3,5,8};//任何数和零异或等于自身，和自身异或等于0
    int result=0;
    for(i=0;i<5;i++){
        result^=arr[i];
    }
    printf("%d\n",result);
    return 0;
}
