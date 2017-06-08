/**
 * 在BST中寻找mode，所谓的mode就是出现次数最多的元素
 * 题目要求不开辟额外空间，搞不定。
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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> mp;
        int max = 0;
        traceStore(root, mp, max);
        vector<int> result;
        for(auto it = mp.cbegin(); it != mp.cend(); ++it)
        {
            if(it->second == max)
                result.push_back(it->first);
        }
        return result;
        
        
    }
    
    void traceStore(TreeNode* root, unordered_map<int, int> &mp, int &max)
    {
        if(root == nullptr)
            return;
        mp[root->val]++;
        max = std::max(mp[root->val], max);
        traceStore(root->left, mp, max);
        traceStore(root->right, mp, max);
    }
};
