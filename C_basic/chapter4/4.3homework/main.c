#include <stdio.h>

int main(){
    int i,j,k,q,count=0;
    for(i=1;i<100;i++){
        for(j=1;j<100-i;j++){
            for(k=1;k<100-i-j;k++){
                for(q=1;q<100-i-j-k;q++){
                    if(100==i+2*j+5*k+10*q && i+j+k+q==40){
                        count++;
                    }
                }
            }
        }
    }
    printf("%d",count);
    return 0;
}

//某人想将手中的一张面值100元的人民币换成10元、5元、2元和1元面值的票子。要求换正好40张，且每种票子至少一张。问：有几种换法？



//int main(){
//    int i,output=1,n;
//    scanf("%d",&n);
//    for(i=1;i<=n;i++){
//        output*=i;
//    }
//    printf("%d",output);
//}

//利用while或者for循环计算n！的值。
//提示：n！＝1*2*3…*n

//int main(void) {
//    int a,b=0,backup_a;
//    scanf("%d",&a);
//    backup_a=a;
//    while(a){
//        b*=10;
//        b+=a%10;
//        a=a/10;
//    }
//    if(backup_a==b){
//        printf("yes");
//    }else{
//        printf("no");
//    }
//    return 0;
//}

//输入一个整型数，判断是否是对称数，如果是，输出yes，否则输出no，不用考虑这个整型数过大，int类型存不下，不用考虑负值；
//例如 12321是对称数，输出yes，124421是对称数，输出yes，1231不是对称数，输出no