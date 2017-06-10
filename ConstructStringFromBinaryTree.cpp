/**
 * 将一个二叉树按照指定格式转换成一个字符串
 *
 Input: Binary tree: [1,2,3,4]
       1
     /   \
    2     3
   /    
  4     

Output: "1(2(4))(3)"

Explanation: Originallay it needs to be "1(2(4)())(3()())", 
but you need to omit all the unnecessary empty parenthesis pairs. 
And it will be "1(2(4))(3)".
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
    string tree2str(TreeNode* t) {
        if(t == nullptr)
            return "";
        string s(to_string(t->val));
        if(t->left)
            s = s + '(' + tree2str(t->left) + ')';
        if(t->right)
            s = s + '(' + tree2str(t->right) + ')';
        return s;
    }
};
