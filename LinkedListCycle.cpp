// Given a linked list, determine if it has a cycle in it.

// Follow up:
// Can you solve it without using extra space?


/**
 * 思路：一个快指针(一次两步), 一个慢指针(一次一步), 从head开始前进
 * 如果两个指针相遇, 说明有循环
 * 如果指针到NULL, 说明链表结束, 没有循环
 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(true) {
            if(!fast || !slow)
                return false;
            
            fast = fast->next;
            slow = slow->next;
            
            if(fast) {
               fast = fast->next; 
                if(fast == slow)
                    return true;
            }
        }
    }
};