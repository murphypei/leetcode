#include "utils.h"

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *less = new ListNode(0);
        ListNode *less_head = less;
        ListNode *greater = new ListNode(0);
        ListNode *greater_head = greater;
        ListNode *tmp = head;
        while (tmp)
        {
            if (tmp->val < x)
            {
                less->next = tmp;
                less = less->next;
            }
            else
            {
                greater->next = tmp;
                greater = greater->next;
            }
            tmp = tmp->next;
        }
        less->next = greater_head->next;
        greater->next = nullptr;
        ListNode *result = less_head->next;
        delete less_head;
        delete greater_head;
        return result;
    }
};