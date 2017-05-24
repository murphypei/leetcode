/**
 * 求树的倾斜度：每个节点的倾斜度定义为左右子树所有节点和的差值，树的倾斜度等于所有节点倾斜度之和
 */

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
    int findTilt(TreeNode* root) {
        vector<int> tilts;
        forwardOrder(root, tilts);
        for(auto i : tilts)
            cout << i << "\t";
            
        return accumulate(tilts.cbegin(), tilts.cend(), 0);
            
    }

private:
    void forwardOrder(TreeNode* root, vector<int> &tilts)
    {
        if(root != nullptr)
        {
            int tilt = abs(calcSum(root->left) - calcSum(root->right));
            tilts.push_back(tilt);
            forwardOrder(root->left, tilts);
            forwardOrder(root->right, tilts);
        }
    }
    
    int calcSum(TreeNode* root)
    {
        if(root != nullptr)
        {
            return root->val + calcSum(root->left) + calcSum(root->right);
        }
        else
        {
            return 0;
        }
    }
};