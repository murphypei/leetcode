#include "utils.h"

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *first = head, *second = head;
        while (n > 0 && first != nullptr)
        {
            first = first->next;
            n--;
        }

        // valid n
        if (n > 0)
        {
            return nullptr;
        }

        if (first)
        {
            // 删除中间节点
            while (first->next)
            {
                first = first->next;
                second = second->next;
            }
            auto tmp = second->next;
            second->next = second->next->next;
            delete tmp;
        }
        else
        {
            // 删除头节点
            auto tmp = head;
            head = head->next;
            delete tmp;
        }
        return head;
    }
};