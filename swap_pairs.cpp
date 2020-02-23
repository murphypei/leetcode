#include "utils.h"
#include <algorithm>

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {

        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *firstNode = head;
        ListNode *secondNode = head->next;
        ListNode *result = new ListNode(0);
        ListNode *resultTmp = result;
        while (firstNode && secondNode)
        {
            swapPairNode(firstNode, secondNode);

            // second is the head after swap
            resultTmp->next = secondNode;

            // next pair
            firstNode = firstNode->next;
            if (!firstNode)
            {
                break;
            }
            secondNode = firstNode->next;
            resultTmp = resultTmp->next->next;
        }
        return result->next;
    }

    inline void swapPairNode(ListNode *first, ListNode *second)
    {
        if (!second)
        {
            return;
        }
        auto tmp = second->next;
        second->next = first;
        first->next = tmp;
    }
};