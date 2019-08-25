struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // 两个指针，间隔为 n
        ListNode *first = head;
        ListNode *second = nullptr;
        int first_step = 0;
        while (first)
        {
            first_step++;
            // 第一个指针先走
            if (first_step < n)
            {
                first = first->next;
            }
            else
            {
                // 第一个指针走了 n 步，第二个指针开始走
                if (first_step == n)
                {
                    second = head;
                }
                // 第一个指针到达末尾
                if (first->next == nullptr)
                {
                    break;
                }
                else // 两个指针一块走
                {
                    first = first->next;
                    second = second->next;
                }
            }
        }

        if (second != nullptr)
        {
            // 如果是头节点，去掉即可
            if (second == head)
            {
                head = head->next;
            }
            else // 非头节点，遍历删除 second 所在的链表节点
            {
                first = head;
                while (first != nullptr)
                {
                    if (first->next == second)
                    {
                        first->next = first->next->next;
                    }
                    first = first->next;
                }
            }
        }
        return head;
    }
};