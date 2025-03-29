#include <stdio.h>
#define MaxSize 20
typedef int ElemType;

typedef struct{
    ElemType data[MaxSize];
    int top;
}SqStack;

void InitStack(SqStack &S){
    S.top=-1;//栈为空
}

bool IsEmpty(SqStack S){
    if(S.top==-1){
        return true;
    } else{
        return false;
    }
}

bool Push(SqStack &S,ElemType i){
    if(MaxSize-1==S.top){
        return false;
    }
    S.data[++S.top]=i;
    return true;
}

bool GetTop(SqStack S,ElemType &m){
    if(IsEmpty(S)){
        return false;
    }
    m=S.data[S.top];
    return true;
}

bool Pop(SqStack &S,ElemType &m){
    if(IsEmpty(S)){
        return false;
    }
    m=S.data[S.top--];
    return true;
}

int main(){
    SqStack S;
    //初始化
    InitStack(S);
    //判空
    bool flag=IsEmpty(S);
    if(flag){
        printf("stack is empty\n");
    }else{
        printf("stack is not empty\n");
    }

    //入栈
    for(int i=3;i>0;i--){
        Push(S,i);
    }

    //取栈顶元素
    ElemType m;
    flag=GetTop(S,m);
    if(flag){
        printf("get %d\n",m);
    }else{
        printf("get nothing\n");
    }

    //出栈
    flag=Pop(S,m);
    if(flag){
        printf("pop %d, top=%d\n",m,S.top);
    }else{
        printf("something went wrong\n");
    }

    return 0;
}