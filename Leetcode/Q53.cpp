#include <vector>
#include <algorithm>
using std::vector;

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> s(n);
//         s[0]=nums[0];
//         for(int i=1;i<n;++i){
//             s[i]=s[i-1]+nums[i];//类似股票涨跌，记录数值波动
//         }

//         int maxSum=nums[0];
//         int minPrefix=0;//记录在下标j之前最小的s[i]
//         for(int j=0;j<n;++j){
//             int cur=s[j]-minPrefix;//用s[j]减去前面最小的s[i]
//             maxSum=std::max(maxSum,cur);
//             minPrefix=std::min(minPrefix,s[j]);
//         }
//         return maxSum;
//     }
// };

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n);
        //dp[0]包含nums[0]最大子数组和，dp[i]包含nums[i]的最大子数组和
        dp[0]=nums[0];
        int maxSum=dp[0];

        for(int i=1;i<n;++i){
            dp[i]=std::max(nums[i],nums[i]+dp[i-1]);
            maxSum=std::max(maxSum,dp[i]);
        }
        return maxSum;
    }
};
