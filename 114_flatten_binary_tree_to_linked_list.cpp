#include "utils.h"

class Solution
{
public:
    void flatten(TreeNode *root)
    {
        while (root != nullptr)
        {
            // 左子树为空。
            if (root->left == nullptr)
            {
                root = root->right;
            }
            // 左子树不为空，找到它的最右边的节点。
            else
            {
                auto left_r = root->left;
                while (left_r->right != nullptr)
                {
                    left_r = left_r->right;
                }
                // 将原来的右子树放到左子树的最右边的节点上。
                left_r->right = root->right;

                // 将原左子树放到右子树节点上。
                root->right = root->left;
                root->left = nullptr;

                root = root->right;
            }
        }
    }
};