#include <stdio.h>

int main(void) {
    int year;
    while(scanf("%d",&year)){
        if(year%4==0&&year%100!=0||year%400==0){
            printf("%d is leap year",year);
        }else{
            printf("%d is not leap year",year);
        }
    }
    int i,j=6;
    i=!!j;
    printf("i value=%d",i);

    return 0;
}
