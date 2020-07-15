#include "utils.h"

class Solution
{
public:
    // 判断链表是否有环，快慢指针。
    bool hasCycle(ListNode *head)
    {

        ListNode *faster{head};
        ListNode *slower{head};

        if (head == nullptr)
            return false;

        while (faster != nullptr && faster->next != nullptr)
        {
            faster = faster->next->next;
            slower = slower->next;
            if (faster == slower)
                return true;
        }
        // 如果 faster 有终点，则一定不是环
        return false;
    }
};