// Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its bottom-up level order traversal as:
// [
//   [15,7],
//   [9,20],
//   [3]
// ]

// 考察的是二叉树的层序遍历

/**
 * 思路： 使用广度优先搜索的方法, 遍历整个树
 * BFS使用队列辅助记录节点
 * 使用计数标记的方法来记录遍历时的层序结果
 * 结果的顺序是反向的, 使用栈来辅助记录结果
 */

 /**
  * Defintion for a binary tree nodes
  struct TreeNode {
      int val;
      TreeNode* left;
      TreeNode* right;
      TreeNode(int x): val(x), left(NULL), right(NULL) {}
  };

  */

class Solution {
public:

    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        result.clear();
        if(root)
            BFS(root);
        return result;
    }

    void BFS(TreeNode* root) {
        // 辅助计数
        int num1 = 1;       // 记录该层[待遍历的]节点个数
        int num2 = 0;       // 记录下层节点个数

        // 辅助遍历的节点队列
        queue<TreeNode* > q;
        q.push(root);

        // 辅助记录结果的栈
        stack<vector<int> > st;

        // 记录每层的结果
        vector<int> vec;

        while(!q.empty()) {
            
            if(num1) {
                TreeNode* node = q.front();
                q.pop();
                vec.push_back(node->val);
                --num1;
                if(node->left) {
                    ++num2;
                    q.push(node->left);
                }
                if(node->right) {
                    ++num2;
                    q.push(node->right);
                }
            }

            if(!num1) {
                num1 = num2;
                num2 = 0;
                st.push(vec);
                vec.clear();
            }
        }

        vec.clear();
        while(!st.empty()) {
            vec = st.top();
            st.pop();
            result.push_back(vec);
        }
    }

private:
    vector<vector<int> > result;
}


