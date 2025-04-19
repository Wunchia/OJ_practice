#include <stdio.h>

int main() {
    int mon,year;
    while(scanf("%d%d",&year,&mon)){
        switch (mon) {
            case 2:printf("mon=%d is %d days\n",mon,28+(year%4==0&&year%100!=0||year%400==0));
            break;
            case 1:printf("mon=%d is 31 days\n",mon);break;
            case 3:printf("mon=%d is 31 days\n",mon);break;
            case 5:printf("mon=%d is 31 days\n",mon);break;
            case 7:printf("mon=%d is 31 days\n",mon);break;
            case 8:printf("mon=%d is 31 days\n",mon);break;
            case 10:printf("mon=%d is 31 days\n",mon);break;
            case 12:printf("mon=%d is 31 days\n",mon);break;
            case 4:printf("mon=%d is 30 days\n",mon);break;
            case 6:printf("mon=%d is 30 days\n",mon);break;
            case 9:printf("mon=%d is 30 days\n",mon);break;
            case 11:printf("mon=%d is 30 days\n",mon);break;
        }
    }

    int i=1,total=0;
    do{
        total+=i;
        i++;
    }while(i<=100);//无论是否满足判断条件，都会先执行一次
    printf("total=%d\n",total);

    return 0;
}
