//新建一个栈，读取标准输入3个整数3 4 5，入栈3 4 5，依次出栈，打印 5 4 3，
//新建循环队列（Maxsize为5），读取标准输入3 4 5 6 7，
//入队7时，队满，打印false，然后依次出队，输出 3 4 5 6

#include <stdio.h>
#define MaxSize 4
typedef int ElemType;

//==========================================
typedef struct{
    ElemType data[MaxSize];
    int top;
}Stack;

void InitStack(Stack &S){
    S.top=-1;
}

bool Push(Stack &S,ElemType n){
    if(MaxSize==S.top+1){
        return false;
    } else {
        S.data[++S.top] = n;
        return true;
    }
}

bool Pop(Stack &S,ElemType &n){
    if(-1==S.top){
        return false;
    }else{
        n=S.data[S.top--];
        return true;
    }
}

void InputStack(Stack &S,ElemType &n){
    for(int i=3;i>0;i--){
        scanf("%d",&n);
        Push(S,n);
    }
}

void OutputStack(Stack &S,ElemType &n){
    while(-1!=S.top){
        Pop(S,n);
        printf("%2d",n);
    }
    printf("\n");
}

//===========================================
typedef struct{
    ElemType data[MaxSize];
    bool flag=false;
    int front,rear;
}Queue;

void InitQueue(Queue &Q){
    Q.front=Q.rear=0;
}

bool IsEmpty(Queue Q){
    if(Q.front==Q.rear&&false==Q.flag){
        return true;
    }else{
        return false;
    }
}

bool IsFull(Queue Q){
    if(Q.front==Q.rear&&true==Q.flag){
        return true;
    }else{
        return false;
    }
}

bool EnQueue(Queue &Q,ElemType n){
    if(IsFull(Q)){
        return false;
    }else{
        Q.data[Q.rear]=n;
        Q.rear=(Q.rear+1)%MaxSize;
        Q.flag=true;
        return true;
    }
}

bool DeQueue(Queue &Q,ElemType &n){
    if(IsEmpty(Q)){
        return false;
    }else{
        n=Q.data[Q.front];
        Q.front=(Q.front+1)%MaxSize;
        Q.flag=false;
        return true;
    }
}

void InputQueue(Queue &Q,ElemType &n){
    bool ret;
    for(int i=5;i>0;i--){
        scanf("%d",&n);
        ret=EnQueue(Q,n);
        if(!ret){
            printf("false\n");
        }
    }
}

void OutputQueue(Queue &Q,ElemType &n){
    while(!IsEmpty(Q)){
        DeQueue(Q,n);
        printf("%2d",n);
    }
    printf("\n");
}

//===========================================
int main(){
    Stack S;
    ElemType n;
    InitStack(S);
    InputStack(S,n);
    OutputStack(S,n);
    Queue Q;
    InitQueue(Q);
    InputQueue(Q,n);
    OutputQueue(Q,n);
    return 0;
}