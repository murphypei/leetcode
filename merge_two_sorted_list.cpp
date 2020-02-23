#include "utils.h"

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (!l1)
        {
            return l2;
        }
        if (!l2)
        {
            return l1;
        }
        ListNode *result = new ListNode(0);
        ListNode *head = result;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                result->next = l1;
                l1 = l1->next;
            }
            else
            {
                result->next = l2;
                l2 = l2->next;
            }
            result = result->next;
        }
        while (l1)
        {
            result->next = l1;
            l1 = l1->next;
            result = result->next;
        }
        while (l2)
        {
            result->next = l2;
            l2 = l2->next;
            result = result->next;
        }
        return head->next;
    }
};