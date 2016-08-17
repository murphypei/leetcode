// Given a linked list, remove the nth node from the end of list and return its head.

// For example,

//    Given linked list: 1->2->3->4->5, and n = 2.

//    After removing the second node from the end, the linked list becomes 1->2->3->5.
// Note:
// Given n will always be valid.
// Try to do this in one pass.


/**
 * 双指针, 一前一后
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head;
        ListNode* pre = head;
        
        while(n > 0 && first->next) {
            first = first->next;
            --n;
        }
        
        // 如果n超过了链表长度, 删除head
        if(n > 0)       
            return head->next;
        
        while(first->next) {
            first = first->next;
            pre = pre->next;
        }
        
        pre->next = pre->next->next;
        
        return head;
    }
};