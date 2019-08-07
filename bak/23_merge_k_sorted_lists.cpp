/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    static ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) {
            return l2;
        }
        if(l2 == nullptr) {
            return l1;
        }
        ListNode* head = new ListNode(0);
        ListNode* result = head;
        ListNode* first = l1;
        ListNode* second = l2;
        while(first && second)  {
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
        result = head->next;
        delete(head);
        return result;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) {
            return nullptr;
        }
        ListNode* l = lists[0]
        for(int i = 1; i < lists.size(); ++i) {
            l = mergeTwoLists(l, lists[i])
        }
  
        return l;
    }
};