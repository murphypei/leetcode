// Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.


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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        else if(!l2)
            return l1;
        else {
            ListNode* head = new ListNode(0);
            ListNode* result = head;
            ListNode* first = l1;
            ListNode* second = l2;
            while(first && second)  {
                cout << " do while " << endl;
                if(first->val <= second->val ) {
                    result->next = first;
                    first = first->next;
                } 
                else if(second->val < first->val) {
                    result->next = second;
                    second = second->next;
                }
                result = result->next;
            }

            while(first) {
                result->next = first;
                first = first->next;
                result = result->next;
            }
            while(second) {
                result->next = second;
                second = second->next;
                result = result->next;
            }
            
            return head->next;
        }
    }
};