// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

// For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
// But the following [1,2,2,null,3,null,3] is not:
//     1
//    / \
//   2   2
//    \   \
//    3    3
// Note:
// Bonus points if you could solve it both recursively and iteratively.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


 /**
  * 递归的方法。
  * 使用递归的思路很简单, 首先判断两棵树是否对称, 然后直接判断树的左右子树(作为两棵树)是否对称
  * 判断两棵树是否对称：一棵树的左子树和和另一颗树的右子树对称, 并且这棵树的右子树和另一棵树的左子树对称, 然后调用递归, 依次向下遍历判断
  * 注意一些条件
  */
class Recursive_Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root)
            return isSymmetric(root->left, root->right);
        else
            return true;
    }
    
    
    // 判断两棵树是否对称, 思路：根节点相等之后, 一个树的左子树应该和另一个数的右子树对称
    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if(left && right) {
            if(left->val == right->val) {
                return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
            }
            
            else {      // 两棵树的根不一样
                return false;
            }
        }
        else if(!left && !right) {      // 两颗空树
            return true;
        }
        else
            return false;
    }
};




/**
 * 迭代的方法。
 * 使用两种不同的遍历方法对两个子树进行方向相反的遍历, 然后比较
 * 这里用到了树的遍历规律, 对于对称的树, 相反方向的遍历, 结果是一样的
 * 使用栈来分别保存遍历的节点
 */

class Iterative_Solution {
public:

    bool isSymmetric(TreeNode* root) {
        if(!root) 
            return true;
        stack<TreeNode* > left_st;
        left_st.push(root->left);
        stack<TreeNode* > right_st;
        right_st.push(root->right);
        
        while(!left_st.empty() && !right_st.empty()) {
            TreeNode* leftNode = left_st.top();
            left_st.pop();
            TreeNode* rightNode = right_st.top();
            right_st.pop();
            
            if(!leftNode && !rightNode) 
                continue;
            else if(!leftNode || !rightNode)
                return false;
            else if(leftNode->val == rightNode->val) {      // 两个子树遍历方向相反
                left_st.push(leftNode->right);
                left_st.push(leftNode->left);
                right_st.push(rightNode->left);
                right_st.push(rightNode->right);
            }
            else
                return false;
        }
        
        return true;
    }
        
        
};