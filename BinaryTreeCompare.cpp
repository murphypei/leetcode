/**
 * 比较两个二叉树是否相等
 * 
 * 思路：不是用递归，利用层序遍历的思想，利用两个队列来辅助进行层序遍历，对每一层的节点个数和数据进行比较
 */

#include <queue>
#include <iostream>

using namespace std;

struct BTreeNode {
    int val;
    BTreeNode* left;
    BTreeNode* right;

    BTreeNode(int n):val(n), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSameTree(BTreeNode* root1, BTreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) {
            return true;
        }
        else if(root1 == nullptr || root2 == nullptr) {
            return false;
        }

        queue<BTreeNode*> q1;
        queue<BTreeNode*> q2;

        q1.push(root1);
        q2.push(root2);


        // 同时进行层序遍历
        while(!q1.empty() && !q2.empty()) {
            
            // 判断这一层的节点个数是否相等
            if(q1.size() != q2.size()) {
                return false;
            }

            int cnt = 0;
            while(cnt++ < q1.size()) {
                BTreeNode* node1 = q1.front();
                BTreeNode* node2 = q2.front();

                if(node1->val != node2->val) {
                    cout << "node1->val != node2->val" << endl;
                    return false;
                }

                q1.pop();
                q2.pop();

                // 判断当前节点的数据是否相等
                if(node1->left != nullptr && node2->left != nullptr) {                
                    q1.push(node1->left);
                    q2.push(node2->left);
                } else if(node1->left == nullptr && node2->left == nullptr) {
                    cout <<"pass" <<endl;
                } else {
                    cout << "node1->left != nullptr && node2->left != nullptr" << endl;
                    return false;
                }

                // 判断当前节点的左右子树的结构是否相等，并相应入队。
                if(node1->right != nullptr && node2->right != nullptr) {                    
                    q1.push(node1->right);
                    q2.push(node2->right);
                } else if(node1->right == nullptr && node2->right == nullptr) {
                    cout <<"pass" <<endl;
                } else {
                    cout << "node1->right != nullptr && node2->right != nullptr" << endl;
                    return false;
                }
            }
        }
        return true;
    }
};