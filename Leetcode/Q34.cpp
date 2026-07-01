#include <vector>
using std::vector;

// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int left=0,right=nums.size()-1;
//         while(left<=right){
//             int mid=left+(right-left)/2;
//             if(nums[mid]<target){
//                 left=mid;
//             }else if(nums[mid]>target){
//                 right=mid;
//             }else{
//                 int start=mid,end=mid;
//                 while(nums[start]==target){
//                     --start;
//                 }
//                 while(nums[end]==target){
//                     ++end;
//                 }
//                 return {start+1,end-1};
//             }
//         }
//     }
// };


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftBorder = findLeftBorder(nums, target);
        int rightBorder = findRightBorder(nums, target);

        // 检查是否找到了有效的边界
        if (leftBorder <= rightBorder && leftBorder >= 0 && rightBorder < nums.size() && nums[leftBorder] == target) {
            return {leftBorder, rightBorder};
        }

        return {-1, -1};
    }

private:
    // 寻找左边界
    int findLeftBorder(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int leftBorder = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                // 当 nums[mid] == target 时，继续向左区间压缩，以锁定最左边的目标
                right = mid - 1;
                if (nums[mid] == target) leftBorder = mid;
            } else {
                left = mid + 1;
            }
        }
        return leftBorder;
    }

    // 寻找右边界
    int findRightBorder(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int rightBorder = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                // 当 nums[mid] == target 时，继续向右区间压缩，以锁定最右边的目标
                left = mid + 1;
                if (nums[mid] == target) rightBorder = mid;
            } else {
                right = mid - 1;
            }
        }
        return rightBorder;
    }
};
