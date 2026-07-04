#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::endl;

typedef int ElemType;

class STable{
public:
    //构造函数
    STable(int len)
    :_len(len)
    ,_table(new ElemType[_len+1])
    {
        srand(time(NULL));
        for(int i=1;i<=_len;++i){
            _table[i]=rand()%100;
        }
    }
    //析构函数
    ~STable(){
        delete[] _table;
    }
    //打印table
    void print(){
        for(int i=1;i<=_len;++i){
            cout<<_table[i]<<" ";
        }
        cout<<endl;
    }
    //辅助工具函数
    void swap(int &a,int &b){
        int tmp=a;
        a=b;
        b=tmp;
    }

    //冒泡排序
    void bsort(){
        bubble_sort(_table, _len);
    }

    //快速排序
    void qsort(){
        quick_sort(_table,1,_len);
    }

    //归并排序

    //堆排序

private:
    size_t _len;
    ElemType* _table;

    //================ 冒泡排序 =======================
    void bubble_sort(ElemType *A,int len){
        bool flag;
        for(int i=0;i<_len-1;++i){
            flag=false;
            for(int j=_len;j>i;--j){
                if(A[j-1]>A[j]){
                    swap(A[j-1], A[j]);
                    flag=true;
                }
            }
            if(flag==false){
                return;
            }
        }
    }

    //================ 快速排序 =======================
    int partition(ElemType *A,int low,int high){
        int pivot=A[low];
        while(low<high){
            while(low<high&&A[high]>pivot){
                --high;
            }
            A[low]=A[high];
            while(low<high&&A[low]<=pivot){
                ++low;
            }
            A[high]=A[low];
        }
        A[low]=pivot;
        return low;//回传的是枢轴下标
    }

    void quick_sort(ElemType *A,int low,int high){
        if(low<high){
            int pivotpos=partition(A, low, high);
            quick_sort(A, low, pivotpos-1);
            quick_sort(A, pivotpos+1, high);
        }
    }
};

int main(int argc,char *argv[])
{
    STable st(10);
    st.print();
    //st.qsort();
    st.bsort();
    st.print();
    return 0;
}
