#include "utils.h"

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *tmp1 = l1;
        ListNode *tmp2 = l2;
        ListNode *resultHead = new ListNode(0); // useless listnode, just help to code
        ListNode *resultTmp = resultHead;
        int r = 0, c = 0;
        while (tmp1 || tmp2)
        {
            r = (tmp1 == nullptr ? 0 : tmp1->val) + (tmp2 == nullptr ? 0 : tmp2->val) + c;
            c = r / 10;
            r = r % 10;
            resultTmp->next = new ListNode(r);
            resultTmp = resultTmp->next;
            if (tmp1 != nullptr)
            {
                tmp1 = tmp1->next;
            }
            if (tmp2 != nullptr)
            {
                tmp2 = tmp2->next;
            }
        }
        if (c > 0)
        {
            resultTmp->next = new ListNode(c);
        }
        ListNode *result = resultHead->next;
        delete resultHead;
        return result;
    }
};