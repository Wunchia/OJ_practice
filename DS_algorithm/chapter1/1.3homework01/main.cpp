#include <stdio.h>
#define MAXSIZE 10
typedef int ElemType;
typedef struct{
    ElemType data[MAXSIZE];
    int len;
}sqlist,*sq;

void InitSqlist(sqlist &s){
    s.data[0]=1;
    s.data[1]=2;
    s.data[2]=3;
    s.len=3;
}

bool Insert(sqlist &s,ElemType val,int pos){
    if(pos<0||pos>=s.len){
        return false;
    }
    if(s.len>MAXSIZE){
        return false;
    }
    for(int i=s.len;i>=pos;i--){
        s.data[i]=s.data[i-1];
    }
    s.data[pos-1]=val;
    s.len++;
    return true;
}

void PrintSqlist(sqlist s){
    for(int i=0;i<s.len;i++){
        printf("%3d",s.data[i]);
    }
    printf("\n");
}

bool Delete(sqlist &s,int pos){
    if(pos<1||pos>s.len){
        return false;
    }
    for(int i=pos;i<s.len;i++){
        s.data[i-1]=s.data[i];
    }
    s.len--;
    return true;
}

int main(){
    sqlist s;
    InitSqlist(s);
    ElemType val;
    int pos;
    int ret;
    scanf("%d",&val);
    Insert(s,val,2);
    PrintSqlist(s);
    scanf("%d",&pos);
    ret=Delete(s,pos);
    if(ret){
        PrintSqlist(s);
    }else{
        printf("false");
    }
    return 0;
}