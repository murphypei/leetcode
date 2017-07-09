/**
 * 二叉树中序遍历的应用：
 * 将一个二叉树转换为Greater而二叉树，后者的定义是将前者的每一个节点都变成原二叉树中节点加上比这个节点大的所有节点和。
 *
 * 很容易找到规律，在BST中，一个节点，比其大的节点就是父节点，父节点的右子树所有节点，以及自身的右子树的所有节点。
 * 把每个节点都加上一个和，而这个和就是比其大的节点的和，在遍历二叉树的时候，也就是要求遍历到当前节点的时候，先遍历到其父节点
 以及父节点的所有右子树节点。可以通过中序遍历很方便的实现
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
    TreeNode* convertBST(TreeNode* root) {
        if(root) {
            convertBST(root->right);
            root->val += sum;
            sum = root->val;
            convertBST(root->left);
        }
        return root;
    }
private:
    int sum = 0;
};
