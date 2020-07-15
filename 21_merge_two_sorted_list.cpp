#include "utils.h"

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *res_head = new ListNode(0);
        ListNode *res = res_head;
        while (l1 && l2)
        {
            if (l1->val > l2->val)
            {
                res->next = l2;
                l2 = l2->next;
            }
            else
            {
                res->next = l1;
                l1 = l1->next;
            }
            res = res->next;
        }
        if (l1)
        {
            res->next = l1;
        }
        else if (l2)
        {
            res->next = l2;
        }
        res = res_head->next;
        delete res_head;
        return res;
    }
};