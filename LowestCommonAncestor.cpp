// Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

//         _______6______
//        /              \
//     ___2__          ___8__
//    /      \        /      \
//    0      _4       7       9
//          /  \
//          3   5
// For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.


/**
 * 在二叉搜索树中找两个节点的最小公共祖先
 * 思路：根据两个节点的值和root的值进行比较确定节点所在子树位置，递归查找
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!p || !q)
            return NULL;
        
        TreeNode* min;
        TreeNode* max;
        if(p->val > q->val) {       // 确定两个节点中较大节点和较小的节点
            max = p;
            min = q;
        }
        else if(p->val < q->val) {
            max = q;
            min = p;
        }
        else {                      // 如果节点相等则返回自身
            return q;
        }
        

        if(max->val > root->val && min->val < root->val)            // 如果两个节点在root两侧，那公共祖先只能是root
            return root;
        else if (max->val < root->val){
            return lowestCommonAncestor(root->left, max, min);      // 如果两个节点都在root左侧，递归在root左子树中查找
        }
        else if(min->val > root->val) {
            return lowestCommonAncestor(root->right, max, min);     // 如果两个节点都在root右侧，递归在root右子树中查找
        }
        else {                                                      // 如果有个节点等于root，则root为公共祖先
            return root;
        }
    }
        
};