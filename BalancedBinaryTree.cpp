/**
 * 求是否是平衡二叉树
 *
 * 思路：首先要知道如何求每个节点的高度
 * 然后判断每个节点的左子树和右子树高度是否满足平衡二叉树的条件
 * 如果高度满足, 再判断每个子节点是不是平衡二叉树(很重要, 因为二叉树的平衡, 不仅仅是在根节点的高度平衡, 而是所有节点！！！)
 */


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        int rh = treeHeight(root->right);
        int lh = treeHeight(root->left);
        if(abs(rh - lh) <= 1)
            return (isBalanced(root->right) && isBalanced(root->left));
        else 
            return false;
            
    }
    
    int treeHeight(TreeNode* root) {
        if(!root)
            return 0;
        int l = treeHeight(root->left) + 1;
        int r = treeHeight(root->right) + 1;
        return l > r ? l : r;
    }
};