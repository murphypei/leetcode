#include "utils.h"
#include <queue>

class Solution
{
public:
    // 判断二叉树是否对称：层序遍历二叉树，判断每一个节点的两个子节点是否对称，关于对称，可以参考解法一。
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }
        std::queue<TreeNode *> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty())
        {
            // 去连续的两个节点
            auto l = q.front();
            q.pop();
            auto r = q.front();
            q.pop();

            // 判断连续的两个节点是否一样
            if (l == nullptr && r == nullptr)
            {
                continue;
            }
            if (l == nullptr || r == nullptr)
            {
                return false;
            }
            if (l->val != r->val)
            {
                return false;
            }

            // 注意，这里入队的顺序，保证连续的两个节点应该是相同的。
            q.push(l->left);
            q.push(r->right);
            q.push(l->right);
            q.push(r->left);
        }
        return true;
    }
};