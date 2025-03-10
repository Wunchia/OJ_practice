#include <stdio.h>

int main(void) {
    int i;
    while(scanf("%d",&i)){
        if(i>0){
            printf("i is bigger than 0\n");
        }else{
            printf("i is not bigger than 0\n");
        }
    }
    return 0;
}
