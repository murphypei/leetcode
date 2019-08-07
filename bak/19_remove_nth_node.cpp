// Given a linked list, remove the n-th node from the end of list and return its head.

// Example:

// Given linked list: 1->2->3->4->5, and n = 2.

// After removing the second node from the end, the linked list becomes 1->2->3->5.

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
        if(head == nullptr) {
            return nullptr;
        }

        ListNode* firstNode = head;
        ListNode* secondNode = head;
        int cnt = 0;
        while(cnt < n && firstNode) {
            firstNode = firstNode->next;
            cnt++;
        }
        if(!firstNode) {
            return head->next;
        }
        while(firstNode->next) {
            firstNode = firstNode->next;
            secondNode = secondNode->next;
        }
        // cout << secondNode->val << endl;
        secondNode->next = secondNode->next->next;
        return head;
    }
   
};