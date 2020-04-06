#include "utils.h"

class Solution
{
public:
    // 判断二叉树是否对称：判断左右子树是否互为镜像；
    // 判断两个二叉树是否互为镜像：根节点相等，左子树互为镜像。
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }
        return isMirror(root->left, root->right);
    }

    bool isMirror(TreeNode *t1, TreeNode *t2)
    {
        if (t1 == nullptr && t2 == nullptr)
        {
            return true;
        }
        if (t1 == nullptr || t2 == nullptr)
        {
            return false;
        }

        return (t1->val == t2->val) && isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
    }
};