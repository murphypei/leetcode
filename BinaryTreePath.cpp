// Given a binary tree, return all root-to-leaf paths.

// For example, given the following binary tree:

//    1
//  /   \
// 2     3
//  \
//   5
// All root-to-leaf paths are:

// ["1->2->5", "1->3"]


/**
 * DFS
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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)
            return result;
        string s;
        DFS(root, s);
        return result;
    }
    
    void DFS(TreeNode* root, string s) {
        if(!root)
            return;
        if(!root->left && !root->right) {  // leaf node
            s += to_string(root->val);
            result.push_back(s);
            return;
        }
        else {
            s = s + to_string(root->val) + "->";
        }
        
        DFS(root->left, s);
        DFS(root->right, s);
        
    }

private:
    vector<string> result;
};
