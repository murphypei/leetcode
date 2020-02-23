#include "utils.h"
#include <vector>

class Solution
{
    ListNode *mergeLists(ListNode *l1, ListNode *l2)
    {
        // Dummy List node head
        ListNode *ret = new ListNode(-1);
        ListNode *retHead = ret;
        while (nullptr != l1 && nullptr != l2)
        {
            if (l1->val > l2->val)
            {
                ret->next = l2;
                l2 = l2->next;
            }
            else
            {
                ret->next = l1;
                l1 = l1->next;
            }
            ret = ret->next;
        }
        if (nullptr != l2)
            ret->next = l2;
        else if (nullptr != l1)
            ret->next = l1;

        // Delete dummy node
        ListNode *tmp = retHead;
        retHead = retHead->next;
        delete tmp;
        return retHead;
    }

public:
    ListNode *mergeKLists(std::vector<ListNode *> &lists)
    {
        int listSize = lists.size();
        // Empty list, return nullptr
        if (0 == listSize)
            return nullptr;

        int interval = 1;
        while (interval < listSize)
        {
            // Merge (n/interval) lists
            for (int i = 0; i < listSize - interval;)
            {
                lists[i] = mergeLists(lists[i], lists[i + interval]);
                i += (interval * 2);
            }
            interval <<= 1; // interval / 2
        }
        return lists[0];
    }
};