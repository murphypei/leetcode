#include "utils.h"

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        auto fast = head;
        auto slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};