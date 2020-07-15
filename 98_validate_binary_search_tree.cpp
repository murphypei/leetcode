#include "utils.h"
#include <limits>
#include <stack>

using namespace std;

// 递归解法
class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        return isValidBST(root, std::numeric_limits<long>::min(), std::numeric_limits<long>::max());
    }

    bool isValidBST(TreeNode *root, long left, long right)
    {
        if (!root)
            return true;
        if (root->val <= left || root->val >= right)
            return false;
        // 注意这里，left 和 right 的值层层向下传递。
        return isValidBST(root->left, left, root->val) && isValidBST(root->right, root->val, right);
    }
};

// 迭代解法，利用 BST 的中序遍历是一个有序数组的特性
class Solution2
{
public:
    bool isValidBST(TreeNode *root)
    {
        stack<TreeNode *> s;
        TreeNode *p = root, *pre = nullptr;
        while (p || !s.empty())
        {
            while (p)
            {
                s.push(p);
                p = p->left;
            }
            p = s.top();
            s.pop();
            if (pre && p->val <= pre->val)
                return false;
            pre = p;
            p = p->right;
        }
        return true;
    }
};