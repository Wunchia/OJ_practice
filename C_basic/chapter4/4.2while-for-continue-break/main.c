#include <stdio.h>

int main(void) {
    int i=1,sum=0;
    while(i<=100){
        if(i%2==1){
            i++;
            continue;//跳过循环内后面的内容直接走到下一次循环
        }
        sum+=i;
        i++;
    }
    printf("sum even from 1 to 100 equals %d\n",sum);
    sum=0;
    int j;
    for(j=1;j<=100;j++){
        if(j%2==0){
            continue;//跳过循环内后面的内容直接走到下一次循环
        }
        if(sum>2000){
            break;
        }
        sum+=j;
    }
    printf("sum odd from 1 to 100 but pause equals %d, j=%d\n",sum,j);


    for(i=0;i<5;i++){
        printf("i=%d\n",i);
        for(j=0;j<5;j++){
            printf("%d ",i*j);
        }
        printf("\n");
    }

    for(i=1;i<10;i++){
        for(j=1;j<i+1;j++){
            printf("%d*%d=%d\t",j,i,i*j);
        }
        printf("\n");
    }

    return 0;
}
