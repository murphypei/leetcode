#include "utils.h"

class Solution
{

    void deleteTarget(ListNode *head, int target)
    {
        if (head->val == target)
        {
            head = head->next;
            return;
        }
        ListNode *tmp = head;
        while (tmp && tmp->next)
        {
            if (tmp->val == target)
            {
                if (tmp->next)
                {
                    tmp->val = tmp->next->val;
                    tmp->next = tmp->next->next;
                }
                else
                {
                    tmp = nullptr;
                }
                break;
            }
            tmp = tmp->next;
        }
    }
};