#include "utils.h"
class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;

        // 计算链表长度
        ListNode *cur = head;
        int len = 0;
        while (cur)
        {
            len++;
            cur = cur->next;
        }

        // 需要注意，每次排序之后，链表都发生了变化，所以 cur 必须从已排序链表的头开始取。
        ListNode *left = nullptr, *right = nullptr;
        for (int size = 1; size < len; size <<= 1)
        {
            cur = dummyHead->next;
            auto tail = dummyHead;
            while (cur)
            {
                left = cur;
                right = splitList(left, size);
                cur = splitList(right, size);
                tail->next = mergeSortedList(left, right);
                while (tail->next)
                {
                    tail = tail->next;
                }
            }
        }
        auto res = dummyHead->next;
        delete dummyHead;
        return res;
    }

private:
    // 辅助函数，用于取子链表，原链表剩余前 n 个，并返回后序的链表。
    ListNode *splitList(ListNode *head, int n)
    {
        ListNode *cur = head;
        ListNode *right;
        while (--n && cur)
        {
            cur = cur->next;
        }
        if (!cur)
        {
            return nullptr;
        }
        right = cur->next;
        // 原链表结尾置空。
        cur->next = nullptr;
        return right;
    }

    // 合并两个有序链表。
    ListNode *mergeSortedList(ListNode *head1, ListNode *head2)
    {
        ListNode *res = new ListNode(-1);
        auto dummyHead = res;
        while (head1 != nullptr && head2 != nullptr)
        {
            if (head1->val < head2->val)
            {
                dummyHead->next = head1;
                head1 = head1->next;
            }
            else
            {
                dummyHead->next = head2;
                head2 = head2->next;
            }
            dummyHead = dummyHead->next;
        }
        if (head1 != nullptr)
        {
            dummyHead->next = head1;
        }
        else
        {
            dummyHead->next = head2;
        }
        dummyHead = res;
        res = dummyHead->next;
        delete dummyHead;
        return res;
    }
};