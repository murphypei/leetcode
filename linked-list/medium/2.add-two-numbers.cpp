/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        auto      h1       = l1;
        auto      h2       = l2;
        ListNode *result   = new ListNode(0);
        ListNode *res_head = result;
        while (h1 || h2)
        {
            int v1 = 0, v2 = 0, res = 0;
            if (h1)
            {
                v1 = h1->val;
                h1 = h1->next;
            }
            if (h2)
            {
                v2 = h2->val;
                h2 = h2->next;
            }
            res         = v1 + v2 + result->val;
            result->val = res % 10;
            if (h1 || h2 || res / 10)
            {
                result->next = new ListNode(res / 10);
                result       = result->next;
            }
        }
        return res_head;
    }
};
// @lc code=end
