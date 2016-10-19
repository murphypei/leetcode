// Find the sum of all left leaves in a given binary tree.

// Example:

//     3
//    / \
//   9  20
//     /  \
//    15   7

// There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

// 求所有左叶子的节点的和


// 思路: 
// 1. 判断传入节点是否非空
// 2. 判断左节点是否存在, 如果存在且为叶子节点，则加到结果上，否则递归调用左子树
// 3. 递归调用右子树


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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)
            return result;
        
        // cout << root->val << endl;
        
        if(root->left) {
            if(isLeaf(root->left))
                result += root->left->val;
            else
                sumOfLeftLeaves(root->left);
        }
        
        if(root->right) {
            sumOfLeftLeaves(root->right);
        }
        
        return result;    
    }
    
    bool isLeaf(TreeNode* node) {
        return node && !node->left && !node->right;
    }
private:
    int result = 0;
};