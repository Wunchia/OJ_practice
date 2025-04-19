#include <stdio.h>

//int main() {
//    int i;
//    scanf("%d",&i);
//    int j,k;
//    j=i<<1;
//    k=i>>1;
//    printf("%2d\n",j);
//    printf("%2d",k);
//    return 0;
//}

int main(){
    int i,j=0,result=0;
    while(j<5){
        scanf("%d",&i);
        result^=i;
        j++;
    }
    printf("%2d",result);
    return 0;
}