// Given a linked list, swap every two adjacent nodes and return its head.

// For example,
// Given 1->2->3->4, you should return the list as 2->1->4->3.

// Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.


/**
 * 思路：节点交换, 记录节点位置
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode* current = head;
        ListNode* preNode = NULL;
        ListNode* prePreNode = NULL;
        
        while(current && current->next) {
            // 选定两个相邻节点
            preNode = current;  
            current = current->next;
            
            // 记录选定节点的下一节点
            ListNode* pNext = current->next;    
            
            // 确定头结点
            if(preNode == head)
                head = current;
            
            
            if(prePreNode)
                prePreNode->next = current;
            
            current->next = preNode;
            preNode->next = pNext;
            
            prePreNode = preNode;
            current = pNext;
        }
        
        return head;
    }
};