#include <vector>
using std::vector;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<32;++i){
            int total=0;
            for(int e:nums){
                total+=((e>>i)&1);//当前位与1异或并求和
            }
            //答案的第 i 个二进制位就是数组中所有元素的第 i 个二进制位之和除以 3 的余数。
            if(total%3){
                ans|=(1<<i);//能够被三整除
            }
        }
        return ans;
    }
};
