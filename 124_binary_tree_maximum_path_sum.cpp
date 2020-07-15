#include "utils.h"
#include <limits>

class Solution
{
public:
    int maxPathSum(TreeNode *root)
    {
        int maxVal = std::numeric_limits<int>::min();
        maxPathSum(root, maxVal);
        return maxVal;
    }

    int maxPathSum(TreeNode *root, int &maxVal)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int leftVal = std::max(0, maxPathSum(root->left, maxVal));
        int rightVal = std::max(0, maxPathSum(root->right, maxVal));

        // 总的最大路径和更新
        int maxTemp = root->val + leftVal + rightVal;
        maxVal = std::max(maxVal, maxTemp);

        // 这里递归的返回要注意：返回的是到当前节点的最大值，因为 root
        // 节点一定是起始或者结尾节点，所以只能选择左子树或者右子树一种路径。
        return root->val + std::max(leftVal, rightVal);
    }
};