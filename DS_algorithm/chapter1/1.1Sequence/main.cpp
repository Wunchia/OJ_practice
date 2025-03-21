#include <stdio.h>

#define MaxSize 10
typedef struct{
    int len;
    int data[MaxSize];
}sqlist;

bool insert(sqlist &s,int index,int val){
    if(s.len>=MaxSize){
        printf("overflow");
        return false;
    }
    if(index>s.len+1){
        printf("invalid index\n");
        return false;
    }
    if(index<=s.len+1){
        for(int j=s.len+1;j>=index;j--){
            s.data[j+1]=s.data[j];
        }
        s.data[index]=val;
        s.len++;
    }
    return true;
}
void print_sqlist(sqlist s){
    for(int i=1;i<=s.len;i++){
        printf("%d ",s.data[i]);
    }
    printf("\n----------\n");
}

int main(){
    sqlist s1;
    s1.len=0;
    for(int i=1;i<MaxSize-1;i++){
        insert(s1,i,i);
        print_sqlist(s1);
    }
    insert(s1,3,66);
    print_sqlist(s1);
    insert(s1,14,66);
    return 0;
}