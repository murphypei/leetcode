/**
 * 二叉树中序遍历的应用：
 * 将一个BST转换为Greater二叉树，后者的定义是将前者的每一个节点都变成原二叉树中节点加上比这个节点大的所有节点和。
 *
 * 很容易找到规律，在BST中，一个节点，比其大的节点分布在两个地方：
   （1）父节点的右子树所有节点
   （2）自身的右子树的所有节点
 * 把每个节点都加上一个和，而这个和就是比其大的节点的和。
 * 如果想要更改整个树的所有节点，就必须遍历整棵树，在这种情况下，我们可以使用中序遍历，先遍历右子树节点，求出和，然后将当前节点加上右子树节点和，然后再遍历左子树。
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


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
