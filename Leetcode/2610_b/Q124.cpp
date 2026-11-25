#include <algorithm>
#include <climits>
using std::max;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxGain(TreeNode* node){
        if(node==nullptr){
            return 0;
        }
        int leftGain=max(maxGain(node->left),0);
        int rightGain=max(maxGain(node->right),0);
        //计算折线 因为前面和0比较过 所以会被记录的折线必然大于直线
        //小于直线的折线在前面已被忽略
        int newPath=leftGain+rightGain+node->val;
        maxSum=max(maxSum,newPath);//记入maxSum

        return node->val+max(leftGain,rightGain);//函数的递归本身只处理直线
    }

    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
private:
    int maxSum=INT_MIN;
};
