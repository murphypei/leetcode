#include "utils.h"

class Solution
{
public:
    // 将链表分为两个长度，非环形头部长度为a，环形长度为 b。fast 步数为 f，slow 步数为 s。
    // 第一次相遇必然是在环内，fast 走了 slow 两倍的长度，而且因为相遇，所以多走的长度必然是环形长度的整倍数，因此
    // f=2s=s+nb，f=2nb，s=nb，也就是此时 slow 走的总长度是 b 的整倍数（n为正整数），这个非常重要。

    // 然后将 fast 重置，然后 fast 和 slow 每次都走一步，当 fast 和 slow 再次相遇，假设 fast 走了 x 步，则
    // f=x，s=x+nb，很明显，当 x=a 时，f=a，s=a+nb，f 和 s 相遇，并且恰好时环形的入口。
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while (1)
        {
            // fast 走到终点，说明链表无环。
            if (fast == nullptr || fast->next == nullptr)
            {
                return nullptr;
            }

            // fast 每次走两步，slow 每次走一步。
            fast = fast->next->next;
            slow = slow->next;

            // 第一次相遇
            if (fast == slow)
            {
                break;
            }
        }

        // 第二次相遇
        fast = head;
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};