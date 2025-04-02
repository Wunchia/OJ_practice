#include <stdio.h>

#define MaxSize 50
typedef int ElemType;
typedef struct{
    int len;
    ElemType data[MaxSize];
}sqlist;

//初始化线性表
bool ListInit1(sqlist &s,int len){
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

bool ListInit2(sqlist &s,int len){
    s.len=0;
    if(len+1>=MaxSize){
        return false;
    }
    for(int i=1;i<=len;i++){
        if(i%2==0) {
            s.data[i] = i;
        }else{
            s.data[i]=6;
        }
        s.len++;
    }
    return true;
}

bool ListInit3(sqlist &s,int len){
    s.len=0;
    if(len+1>=MaxSize){
        return false;
    }
    for(int i=1;i<=len;i++){
        if(i<3) {
            s.data[i] = 1;
        }else if(i<7){
            s.data[i]=i;
        } else{
            s.data[i]=8;
        }
        s.len++;
    }
    return true;
}

//打印线性表信息
void PrintSqlist(sqlist s){
    for(int i=1;i<=s.len;i++){
        printf("%3d ",s.data[i]);
    }
    printf("\nlen=%d\n",s.len);
    printf("----------\n");
}

//====================================================================
//02.设计一个高效算法，将顺序表L的所有元素逆置，要求算法的空间复杂度为O(1)。
bool Reverse(sqlist &S){
    if(0==S.len){
        return false;
    }
    ElemType temp;
    int i=1,j=S.len;
    while(i<=j){
        temp=S.data[i];
        S.data[i]=S.data[j];
        S.data[j]=temp;
        i++;
        j--;
    }
    return true;
}
//============================================================================================
//03.对长度为n的顺序表L，编写一个时间复杂度为O(n)、空间复杂度为O(1)的算法，该算法删除顺序表中所有值为x的元素。
void Del_x_1(sqlist &S,ElemType x){
    int idx,not_equal=0;
    for(idx=1;idx<=S.len;idx++){
        if(S.data[idx]!=x){
            not_equal++;
            S.data[not_equal]=S.data[idx];
        }//只有值不为x的元素才执行
    }
    S.len=not_equal;
}

void Del_x_2(sqlist &S,ElemType x){
    int idx=1,count_equal=0;
    while(idx<=S.len){
        if(S.data[idx]==x){
            count_equal++;//值为x只记录个数，不写入数组
        }else{
            S.data[idx-count_equal]=S.data[idx];//不为x，踩踏式写入数组
        }
        idx++;
    }
    S.len=S.len-count_equal;
}

//============================================================
//04.从顺序表中删除其值在给定值s和t之间（包含s和t，要求s<t）的所有元素。
// 若s或t不合理或顺序表为空，则显示出错信息并退出运行。
bool Del_Interval(sqlist &S,ElemType s,ElemType t){
    if(s>=t||S.len==0){
        return false;
    }
    int idx=1,count_target=0;
    while(idx<=S.len){
        if(S.data[idx]>=s&&S.data[idx]<=t){
            count_target++;
        }else{
            S.data[idx-count_target]=S.data[idx];
        }
        idx++;
    }
    S.len=S.len-count_target;
    return true;
}

//====================================================
//05.从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同。
void Del_Repeat(sqlist &S){
    int count_del=0;
    for(int i=2;i<=S.len;i++){
        if(S.data[i]==S.data[i-1]){
            count_del++;
        }else{
            S.data[i-count_del]=S.data[i];
        }
    }
    S.len=S.len-count_del;
}

//===========================================================
//06.将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表。
sqlist Merge(sqlist s1,sqlist s2){
    sqlist t;
    int i=1,j=1,idx=1;
    while(i<=s1.len&&j<=s2.len){
        if(s1.data[i]<=s2.data[j]){
            t.data[idx]=s1.data[i];
            idx++;
            i++;
        }else{
            t.data[idx]=s2.data[j];
            idx++;
            j++;
        }
    }
    while(i<=s1.len){
        t.data[idx]=s1.data[i];
        idx++;
        i++;
    }
    while(j<=s2.len){
        t.data[idx]=s2.data[j];
        idx++;
        j++;
    }
    t.len=--idx;
    return t;
}

//=======================================
//07.已知在一维数组A[m+n]中依次存放两个线性表(a1, a2, a3, ..., am)和(b1, b2, b3, ..., bn)。
//编写一个函数，将数组中两个顺序表的位置互换，即将(b1, b2, b3, ..., bn)放在(a1, a2, a3, ..., am)的前面。
bool ReverseA(ElemType A[],int left,int right,int len){
    ElemType  temp;
    if(left>=right||right>=len){
        return false;
    }
    while(left<right){
        temp=A[left];
        A[left]=A[right];
        A[right]=temp;
        left++;
        right--;
    }
    return true;
}
void Exchange(ElemType A[],int m,int n,int len){
    ReverseA(A,0,m+n-1,len);
    ReverseA(A,n,m+n-1,len);
    ReverseA(A,0,n-1,len);
}

void printA(ElemType A[],int len){
    printf("%3d\n",len);
    for(int i=0;i<len;i++){
        printf("%3d",A[i]);
    }
    printf("\n---------------\n");
}
//=====================================================
//08.线性表(A1, A2, A3, ..., an)中的元素递增有序且按顺序存储于计算机内。要求设计一个算法，
//完成用最少时间在表中查找数值为x的元素，若找到，则将其与后继元素位置相交换，
//若找不到，则将其插入表中并使表中元素仍递增有序。
void ExcangeX(sqlist &s,ElemType x){
    ElemType temp;
    int i;
    for(i=1;i<=s.len;i++){
        if(x==s.data[i]){//成功找到x
            if(s.len==i){//在末尾找到，无后继不用换
                break;
            }
            temp=s.data[i];
            s.data[i]=s.data[i+1];
            s.data[i+1]=temp;
            break;
        }else if(s.data[i]>x){//没找到，应插在中间
            for(int j=s.len;j>=i;j--){
                s.data[j+1]=s.data[j];
            }
            s.data[i]=x;
            s.len++;
            break;
        }else if(i==s.len){//没找到，应插在末尾
            s.data[i+1]=x;
            s.len++;
        }
    }
}

//============================================================
//09.给定三个序列A、B、C，长度均为n，且均为无重复元素的递增序列，请设计一个时间上尽可能高效的算法，
// 逐行输出同时存在于这三个序列中的所有元素。例如，数组A为{1,2,3}，数组B为{2,3,4}，数组C为{-1,0,2}，则输出2。
// 要求：
//  给出算法的基本设计思想。//用三个下标变量同时从小到大遍历三个数组，相等则输出且三个下标同时加一，否则最小的对应下标加一
//  根据设计思想，采用C或C++语言描述算法，关键之处给出注释。
//  说明你的算法的时间复杂度和空间复杂度。//O(n)
void PrintSame(ElemType A[],ElemType B[],ElemType C[],int n){
    int i,j,k;
    i=j=k=0;
    while( i<n && j<n && k<n ){
        if(A[i]==B[j]&&B[j]==C[k]){
            printf("%d\n",A[i]);
            i++;j++;k++;
        }else{
            if(A[i]<=B[j]&&A[i]<=C[k]){
                i++;
            }else if(B[j]<=A[i]&&B[j]<=C[k]){
                j++;
            }else{
                k++;
            }
        }
    }
}

//===================================================================
//10.【2010统考真题】设将n(n>1)个整数存放到一维数组R中。设计一个在时间和空间两方面都尽可能高效的算法。
// 将R中保存的序列循环左移p(0<p<n)个位置，即将R中的数据由(X0, X1, ..., Xn-1)
// 变换为(Xp, Xp+1, ..., Xn-1, X0, X1, ..., Xp-1)。
// 要求：
//  给出算法的基本设计思想。
//  根据设计思想，采用C或C++或Java语言描述算法，关键之处给出注释。
//  说明你所设计算法的时间复杂度和空间复杂度。



int main(){
    sqlist S;
    sqlist S2;
    ListInit1(S,9);//顺序不重复
    ListInit2(S,9);//含重复元素,乱序
    ListInit3(S2,9);//顺序重复
    PrintSqlist(S);
    PrintSqlist(S2);
//  ==========================
    //02.
    Reverse(S);
    //03.
    Del_x_1(S,6);
    Del_x_2(S,6);
    //04.
    Del_Interval(S,4,7);
    //05.
    Del_Repeat(S);
    //06.
    S= Merge(S,S2);
    PrintSqlist(S);//输出验证
//=================================
    //07.
    int T[10];
    for(int i=0;i<10;i++){
        if(i<6){
            T[i]=i;
        }else{
            T[i]=i-6;
        }
    }
    printA(T,10);
    Exchange(T,6,4,10);
    printA(T,10);
//=================================
    //08.
    ExcangeX(S,7);
    PrintSqlist(S);//输出验证
//=================================
    //09.
    ElemType A[3],B[3],C[3];
    A[0]=1;A[1]=2;A[2]=3;
    B[0]=1;B[1]=3;B[2]=4;
    C[0]=0;C[1]=1;C[2]=3;
    PrintSame(A,B,C,3);
//==================================

    return 0;
}