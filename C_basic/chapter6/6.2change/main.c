#include <stdio.h>

void change(int j){//值传递
    j=5;
}

void change2(int *j){//依然是值传递 但是传的是地址
    *j=5;
}

int main(void) {
    int i=10;
    printf("before change i=%d\n",i);
    change(i);
    printf("after chagne i=%d\n",i);

    int k=10;
    printf("before change2 k=%d\n",k);
    change2(&k);
    printf("after chagne2 k=%d\n",k);

    return 0;
}
