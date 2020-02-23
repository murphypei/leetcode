#include "utils.h"

using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
        {
            return head;
        }
        
        ListNode* prev = head;
        ListNode* cur = head->next;
        while(cur)
        {
            if (prev->val != cur->val)
            {
                prev->next = cur;
                prev = cur;
            }
            cur = cur->next;
        }
        prev->next = nullptr;
        return head;
    }
};