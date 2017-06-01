/**
 * 求一棵树t是不是另一个树s的子树
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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == t)
        {
            return true;
        }
        else if(isSame(s, t))
        {
            return true;
        }
        else
        {
            return (s->left && isSubtree(s->left, t)) || (s->right && isSubtree(s->right, t));
        }
            
    }
    
    // 判断两棵树是否相同
    bool isSame(TreeNode *a, TreeNode *b)
    {
        if(a == b)
        {
            return true;
        }
        else if(a && b && a->val == b->val)
        {
            return isSame(a->left, b->left) && isSame(a->right, b->right);
        }
        else
        {
            return false;
        }
    }
};