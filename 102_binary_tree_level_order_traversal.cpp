#include "utils.h"

#include <queue>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        queue<TreeNode *> cur_level;
        queue<TreeNode *> next_level;
        cur_level.push(root);
        while (1)
        {
            vector<int> r;
            while (!cur_level.empty())
            {
                auto node = cur_level.front();
                cur_level.pop();
                if (node)
                {
                    r.push_back(node->val);
                    next_level.push(node->left);
                    next_level.push(node->right);
                }
            }
            if (!r.empty())
            {
                res.push_back(r);
            }
            else
            {
                return res;
            }
            cur_level = next_level;
            while (!next_level.empty())
            {
                next_level.pop();
            }
        }
    }
};