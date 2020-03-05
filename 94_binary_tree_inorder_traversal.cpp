#include "utils.h"
#include <stack>
#include <vector>

using namespace std;
class Solution
{
public:
    // 二叉树中序遍历，递归很简单，这里使用迭代法
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> st;
        TreeNode *temp = root;
        while (temp || !st.empty())
        {
            // 当前节点不为空，则一直深度探索其左节点，注意用栈保存路径
            while (temp)
            {
                st.push(temp);
                temp = temp->left;
            }

            // 取出栈顶元素
            temp = st.top();
            st.pop();

            result.push_back(temp->val);

            // 然后探索右子树节点
            temp = temp->right;
        }
        return result;
    }
};