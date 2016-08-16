// Given a binary tree, find its minimum depth.

// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

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
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        int MIN = 99999;
        DFS(root, MIN, 1);
        return MIN;

    }
    
    void DFS(TreeNode* root, int& MIN, int step) {
        if(!root)
            return;
        if(!root->left && !root->right) {   // leaf node
            if(MIN > step) 
                MIN = step;
            return;
        }
        DFS(root->left, MIN, step + 1);
        DFS(root->right, MIN, step + 1);
    }
};