// Given a sorted linked list, delete all duplicates such that each element appear only once.

// For example,
// Given 1->1->2, return 1->2.
// Given 1->1->2->3->3, return 1->2->3.


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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* front = head;
        ListNode* current = head->next;
        while(current) {
            if(current->val == front->val && current->next) {
                // cout << current->val << endl;
                front->next = current->next;
                delete current;
                current = front->next;
            }
            else if(current->val == front->val) {
                // cout << "***" << current->val << endl;
                delete current;
                current = NULL;
                front->next = NULL;
            }
            else {
                // cout << "do while" << endl;
                front = current;
                current = current->next;
            }
        }
        
        return head;
        
    }
};