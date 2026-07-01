// Q4 寻找两个正序数组的中位数
// 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
// 请你找出并返回这两个正序数组的 中位数 。
// 算法的时间复杂度应该为 O(log (m+n)) 。

// 示例 1：
// 输入：nums1 = [1,3], nums2 = [2]
// 输出：2.00000
// 解释：合并数组 = [1,2,3] ，中位数 2

// 示例 2：
// 输入：nums1 = [1,2], nums2 = [3,4]
// 输出：2.50000
// 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5

#include <vector>
#include <algorithm>
using std::vector;
using std::min;

int findKth(vector<int>& nums1,vector<int>& nums2,int k){
    int m=nums1.size();
    int n=nums2.size();
    int i=0,j=0;//虚拟起始下标 不断右移切掉不可能包含第k小元素的区间
    while(1){//每轮试图丢弃 k/2个元素 然后k减少 i或j右移
        if(i==m){//如果nums1已经全部丢弃
            return nums2[j+k-1];//nums2中的第k小就是需要的
        }
        if(j==n){//如果nums2已经全部丢弃
            return nums1[i+k-1];//nums1中的第k小就是需要的
        }
        if(k==1){//如果k减少到1 nums1中的第一个元素和nums2中的第一个元素 谁小就是谁
            return min(nums1[i],nums2[j]);
        }
        int step=k/2;//每轮试图丢弃 k/2个元素 然后k减少 i或j右移
        int idx1=min(i+step-1,m-1);//防止越界，取step个元素的位置或数组末尾位置
        int idx2=min(j+step-1,n-1);//防止越界，取step个元素的位置或数组末尾位置
        if(nums1[idx1]<=nums2[idx2]){
            //各迈了k/2步，因此较小的那边（nums1）前面凑不够k个更小的，一定排不到第k位，可以安全切掉
            int excluded=idx1-i+1;//计算nums1[i ... idx1]这段区间的元素个数
            k-=excluded;//这excluded个元素不可能是第k小，所以k向前缩减（例如：第7小缩到第4小）
            i=idx1+1;//虚拟起始位置向后移动，跳到被切部分之后，后续只看[i ...]
        }else{
            //各迈了k/2步，因此较小的那边（nums2）前面凑不够k个更小的，一定排不到第k位，可以安全切掉
            int excluded=idx2-j+1;//统计要切掉的个数
            k-=excluded;//切掉后更新k
            j=idx2+1;//虚拟起始位置向后移（切掉前面的）
        }
    }
}

double findMedianSortedArrays(vector<int>& nums1,vector<int>& nums2){
    int totalSize=nums1.size()+nums2.size();
    if(totalSize%2!=0){
        return findKth(nums1,nums2,totalSize/2+1);
    }else{
        double l=findKth(nums1,nums2,totalSize/2);
        double r=findKth(nums1,nums2,totalSize/2+1);
        return (l+r)/2;
    }
}
