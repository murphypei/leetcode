/**
 * 找出BST中任意两个节点之间的最小差值
 * 
 * 思路：利用中序遍历可以得到而二叉查找树所有节点的有序排列，任意小的差值必然出现在排列中相邻的两个节点
 */

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};


class Solution
{
public:
    int getMinimumDifference(TreeNode* root) 
    {
        vector<int> orders;
        inorder(root, orders);
            
        int diff = orders[1] - orders[0];
        int cur, pre;
        for(int i = 2; i < orders.size(); ++i)
        {
            diff = min(diff, orders[i] - orders[i - 1]);
        }
        
        return diff;
    }
private:
    void inorder(TreeNode* root, vector<int> &res)
    {
        if(root != nullptr)
        {
            inorder(root->left, res);
            res.push_back(root->val);
            inorder(root->right, res);
        }
    }
};


int main()
{
    cout << "success" << endl;

    getchar();
    return 0;
}