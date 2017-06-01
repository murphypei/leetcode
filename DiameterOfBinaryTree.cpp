/** 
 * 求二叉树的直径
 * 树的直径的定义：两个距离最远的节点之间的距离
 * 根据定义可以得知，这连个节点之间必然有公共节点，而对于公共节点，直接就是求出左右子树的高度再相加即可。
 * 采用深度遍历的方式对每个节点求出左右子树高度和，更新直径的值

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
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return maxDiameter;
    }

    int dfs(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        int leftDepth = dfs(root->left);
        int rightDepth = dfs(root->right);

        maxDiameter = max(Diameter, leftDepth + rightDepth);
        return max(leftDepth, rightDepth) + 1; 
    }
private:
    int maxDiameter;
};



class