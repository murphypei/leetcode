#include "utils.h"

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *first = head, *second = head;

        // To prevent too large of k
        int len = 1;
        while (first->next)
        {
            first = first->next;
            len++;
        }
        k = k % len;
        first = head;

        // first pointer forward k step
        for (int i = 0; i < k; ++i)
        {
            first = first->next;
            if (first == nullptr)
            {
                first = head;
            }
        }

        // first pointer forward to tail of list
        while (first->next)
        {
            first = first->next;
            second = second->next;
        }

        // first and second both in the tail of list
        if (second->next == nullptr)
        {

            return head;
        }

        ListNode *res_head = second->next;
        first->next = head;
        second->next = nullptr;
        return res_head;
    }
};