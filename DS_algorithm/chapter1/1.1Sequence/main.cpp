#include <stdio.h>

#define MaxSize 50
typedef int ElemType;
typedef struct{
    int len;
    ElemType data[MaxSize];
}sqlist;

//初始化线性表
bool ListInit(sqlist &s,int len){
    s.len=0;
    if(len+1>=MaxSize){
        return false;
    }
    for(int i=1;i<=len;i++){
        s.data[i]=i;
        s.len++;
    }
    return true;
}

//插入元素
bool ListInsert(sqlist &s,int pos,ElemType val){
    if(s.len+1==MaxSize){
        return false;
    }
    if(1>pos||pos>s.len+1){
        return false;
    }
    for(int i=s.len+1;i>pos;i--){
        s.data[i]=s.data[i-1];
    }
    s.data[pos]=val;
    s.len++;
    return true;
}

//删除元素
bool ListDel(sqlist &s,int pos,int &del){
    if(pos>s.len||pos<1){
        return false;
    }
    del=s.data[pos];
    for(int i=pos;i<s.len;i++){
        s.data[i]=s.data[i+1];
    }
    s.len--;
    return true;
}

//修改元素
bool ListChange(sqlist &s,int pos,ElemType val){
    if(pos<1||pos>s.len){
        return false;
    }
    s.data[pos]=val;
    return true;
}

//按位查询元素
bool ListSearch(sqlist s,int pos,ElemType &val){
    if(pos<1||pos>s.len){
        return false;
    }
    val=s.data[pos];
    return true;
}

//按值查找
bool ListLocate(sqlist s,ElemType val,int &pos){
    if(s.len<1){
        return false;
    }
    int i=1;
    for(;i<=s.len;i++){
        if(s.data[i]==val){
            pos=i;
            return true;
        }
    }
    return false;
}

//打印线性表信息
void PrintSqlist(sqlist s){
    for(int i=1;i<=s.len;i++){
        printf("%3d ",s.data[i]);
    }
    printf("\nlen=%d\n",s.len);
    printf("----------\n");
}

int main(){
    sqlist L;
    bool ret;//接收函数返回值
    ElemType del;//接受删除的元素值
    ElemType val;//返回查询的元素值
    ElemType pos;//返回按值查找的位置

    //初始化
    ListInit(L,10);
    PrintSqlist(L);

    //插入
    ret=ListInsert(L,2,60);
    if(ret){
        printf("insert success\n");
    }else{
        printf("insert fail\n");
    }
    PrintSqlist(L);

    //删除
    ret=ListDel(L,2,del);
    if(ret){
        printf("delete %d success\n",del);
    }else{
        printf("delete fail\n");
    }
    PrintSqlist(L);

    //修改
    ret= ListChange(L,2,88);
    if(ret){
        printf("change success\n");
    }else{
        printf("change fail\n");
    }
    PrintSqlist(L);

    //按位查找
    ret= ListSearch(L,2,val);
    if(ret){
        printf("search %d success\n",val);
    }else{
        printf("search fail\n");
    }
    PrintSqlist(L);

    //按值查找
    ret= ListLocate(L,88,pos);
    if(ret){
        printf("locate in %d success\n",pos);
    }else{
        printf("locate fail\n");
    }
    PrintSqlist(L);

    return 0;
}