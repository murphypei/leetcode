#include "utils.h"
#include <vector>

using namespace std;

class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.empty() || inorder.empty())
        {
            return nullptr;
        }
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode *buildTree(vector<int> &preorder, int plo, int phi, vector<int> &inorder, int ilo, int ihi)
    {

        TreeNode *root = new TreeNode(preorder[plo]);

        // 在中序数组中寻找根节点
        int i = ilo;
        while (i <= ihi && inorder[i] != preorder[plo])
        {
            i++;
        }

        // 根据根节点在中序数组中的位置，计算两个子树的长度
        int left_len = i - ilo;
        int right_len = ihi - i;

        if (left_len > 0)
        {
            root->left = buildTree(preorder, plo + 1, plo + left_len, inorder, ilo, ilo + left_len - 1);
        }
        if (right_len > 0)
        {
            root->right = buildTree(preorder, plo + left_len + 1, phi, inorder, ilo + left_len + 1, ihi);
        }
        return root;
    }
};