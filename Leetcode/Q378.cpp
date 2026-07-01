// 给你一个 n x n 矩阵 matrix ，其中每行和每列元素均按升序排序，找到矩阵中第 k 小的元素。
// 请注意，它是 排序后 的第 k 小元素，而不是第 k 个 不同 的元素。
// 你必须找到一个内存复杂度优于 O(n2) 的解决方案。

// 示例 1：
// 输入：matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
// 输出：13
// 解释：矩阵中的元素为 [1,5,9,10,11,12,13,13,15]，第 8 小元素是 13

// 示例 2：
// 输入：matrix = [[-5]], k = 1
// 输出：-5

#include <vector>
using std::vector;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        // 值域二分 left是最小值 right是最大值
        int left=matrix[0][0],right=matrix[n-1][n-1];
        while(left<right){
            int mid=left+(right-left)/2;//值域二分
            int count=0; //统计 <=mid 的元素个数
            int i=n-1,j=0; //i是该列路径位置之上的元素个数 j是该行路径位置之左的元素个数
            while(i>=0&&j<n){
                if(matrix[i][j]<=mid){
                    ++j;//满足条件往右走
                    count+=i+1;//把当前位置和同一列比自己小的都记入
                }else{
                    --i;//不满足条件往上走
                }
            }
            if(count<k){//不够k个 朝大了找 往右下去找
                left=mid+1;
            }else{//超过或等于k个 朝小了找 但不排除mid 往左上去找
                right=mid;
            }
        }
        return left;
    }
};
