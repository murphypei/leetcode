/**
 * 在二叉树中找到路径之和等于给定target的路径有多少条
 * 路径的起点和终点不受限制，但是路径只能是从父到子的顺序
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
    int rootSum(TreeNode* root, int sum) {
        if (root == nullptr)
            return 0;
        return (sum == root->val) + rootSum(root->left, sum - root->val) + rootSum(root->right, sum - root->val);
    }
    
    int pathSum(TreeNode* root, int sum) {
        if (root == nullptr)
            return 0;
        return rootSum(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};