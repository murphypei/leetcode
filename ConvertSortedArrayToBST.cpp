/**
 * 将有序的数组转化为一个BST
 * 中序遍历的思想
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty())
        {
            return nullptr;
        }
        else if(nums.size() < 2)
        {
            TreeNode* node = new TreeNode(nums[0]);
        }
        // 找到数组的中间位置
        int midIdx = nums.size() / 2;
        TreeNode* root = new TreeNode(nums[midIdx]);
        // 数组前半部分构成左子树，后半部分构成右子树
        vector<int> smaller(nums.begin(), nums.begin() + midIdx);
        vector<int> bigger(nums.begin() + midIdx + 1, nums.end());
        root->left = sortedArrayToBST(smaller);
        root->right = sortedArrayToBST(bigger);
        return root;
    }
};