#include "utils.h"

using namespace std;

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head || !(head->next))
        {
            return head;
        }
        ListNode *previous = head, *cur = head->next, *next = nullptr;
        bool previous_valid = true;
        ListNode *res_tmp = new ListNode(0);
        ListNode *res = res_tmp;
        while (cur)
        {
            if (cur->val != previous->val)
            {
                if (previous_valid)
                {
                    res_tmp->next = previous;
                    res_tmp = res_tmp->next;
                }
                // 重置 previous 和 previous_valid
                previous = cur;
                previous_valid = true;
            }
            else
            {
                // preivous 也将失效，直到 cur != previous，重置 previous 和 previous_valid
                previous_valid = false;
            }
            cur = cur->next;
        }
        if (previous_valid)
        {
            res_tmp->next = previous;
        }
        else
        {
            res_tmp->next = nullptr;
        }

        res_tmp = res->next;
        delete res;
        return res_tmp;
    }
};