#include "utils.h"
#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    // 利用栈后序遍历二叉树，保存每个节点的边界情况。
    vector<int> postorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> nodes;
        stack<int> uppers;
        stack<int> lowers;
        TreeNode *current = root;
        vector<int> result;

        // 记录上一次被访问的节点，用于辅助后序遍历
        TreeNode *last = nullptr;

        while (!nodes.empty() || current)
        {
            // 左节点入栈
            if (current)
            {
                nodes.push(current);
                current = current->left;
            }
            else
            {
                current = nodes.top();
                if (current->right && current->right != last)
                {
                    current = current->right;
                }
                else
                {
                    result.push_back(current->val);
                    last = current;
                    nodes.pop();
                    current = nullptr;
                }
            }
        }
        return result;
    }
};

int main()
{
    auto node1 = new TreeNode{1};
    auto node2 = new TreeNode{2};
    auto node3 = new TreeNode{3};
    auto node4 = new TreeNode{4};
    auto node5 = new TreeNode{5};
    auto node6 = new TreeNode{6};
    auto node7 = new TreeNode{7};

    node4->left = node2;
    node4->right = node6;

    node2->left = node1;
    node2->right = node3;

    node6->left = node5;
    node6->right = node7;

    TreeNode *root = node4;

    Solution s;
    s.isValidBST(root);
}
