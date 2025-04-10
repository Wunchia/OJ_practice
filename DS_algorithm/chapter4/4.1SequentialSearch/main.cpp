#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int ElemType;
typedef struct{
    ElemType *elem;
    int TableLen;
}SSTable;

void ST_Init(SSTable &ST,int len){
    ST.TableLen=len+1;//第0个位置放哨兵
    ST.elem=(ElemType*)malloc(sizeof(ElemType)*ST.TableLen);
    srand(time(NULL));//随机数生成
    for(int i=1;i<ST.TableLen;i++){
        ST.elem[i]=rand()%100;//为了随机数都在0-99之间
    }
}

void ST_Print(SSTable ST){
    for(int i=1;i<ST.TableLen;i++){
        printf("%3d",ST.elem[i]);
    }
    printf("\n");
}

int SeqSearch(SSTable ST,ElemType key){
    ST.elem[0]=key;
    int i;
    for(i=ST.TableLen-1;ST.elem[i]!=key;i--);//从后向前找，找到即返回pos，没找到则在哨兵处返回0
    return i;
}

int main(){
    SSTable ST;
    ElemType key;
    int pos;
    ST_Init(ST,10);
    ST_Print(ST);
    printf("choose your search key:\n");
    scanf("%d",&key);
    pos=SeqSearch(ST,key);
    if(pos) {
        printf("key: %d is at the pos of %d\n", key, pos);
    }else{
        printf("not find\n");
    }
    return 0;
}