// 给定一个 排序好 的数组 arr ，两个整数 k 和 x ，
// 从数组中找到最靠近 x（两数之差最小）的 k 个数。
// 返回的结果必须要是按升序排好的。
//整数 a 比整数 b 更接近 x 需要满足：
//  |a - x| < |b - x| 或者
//  |a - x| == |b - x| 且 a < b
#include <algorithm>
#include <vector>
using std::vector;

// class Solution {
//     public:
//         vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//             int pos=binarySearch(arr, x);
//             vector<int> result={arr[pos]};
//             int left=1,right=1;
//             for(int i=1;i<k;++i){
//                 if(pos-left<0){
//                     result.push_back(arr[pos+right]);
//                     ++right;
//                 }else if(pos+right>arr.size()-1){
//                     result.push_back(arr[pos-left]);
//                     ++left;
//                 }else{
//                     if(abs(arr[pos]-x)>abs(arr[pos+right]-x)){
//                         result.push_back(arr[pos+right]);
//                         ++right;
//                     }else{
//                         result.push_back(arr[pos-left]);
//                         ++left;
//                     }
//                 }
//             }
//             std::sort(result.begin(),result.end());
//             return result;
//         }

//     private:
//         int binarySearch(vector<int> &arr,int target){
//             int left=0,right=arr.size()-1;
//             while(left<right){
//                 int mid=left+(right-left)/2;
//                 if(arr[mid]<target){
//                     left=mid+1;
//                 }else if(arr[mid]>target){
//                     right=mid;
//                 }
//             }
//             return left;
//         }
// };


// class Solution {
// public:
//     vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//         sort(arr.begin(),arr.end(),[x](int a,int b)->bool{
//             return abs(a-x)<abs(b-x)||((a-x)==(b-x)&&(a<b));
//         });
//         sort(arr.begin(),arr.begin()+k);
//         return vector<int>(arr.begin(),arr.begin()+k);
//     }
// };

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int right=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        int left=right-1;
        while(k--){
            if(left<0){
                right++;
            }else if(right >=arr.size()){
                left--;
            }else if(x-arr[left]<=arr[right]-x){
                left--;
            }else{
                right++;
            }
        }
        return vector<int>(arr.begin()+left+1,arr.begin()+right);
    }
};
