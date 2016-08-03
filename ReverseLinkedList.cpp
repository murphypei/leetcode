// Reverse a singly linked list.


/**
 * Definition for singly-linked list.
 * struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x):val(x), next(NULL){}
 };

 **/
class Solution {

public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) 
            return head;
        
        // 从第二位开始操作
        ListNode* current = head->next;
        // 记录操作位前一位
        ListNode* front = head;
        
        while(current->next) {
            ListNode* tmp = current;
            // 将当前操作位next指向前一位(reverse)
            tmp->next = front;
            // 操作位后移
            current = current->next;
            // 前一位标记指针也后移(此处千万不能用front = front->next, 因为front->next已经反转了, 不指向后面, 指向前面)
            front = tmp;
        }
        current->next = front;
        // !!!头指针必须清空, 否则会出现循环链表
        head->next = NULL;
        return current;
    }
};