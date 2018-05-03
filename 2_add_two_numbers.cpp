// You are given two non-empty linked lists representing two non-negative integers. 
// The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* tmp1 = l1;
        ListNode* tmp2 = l2;
        ListNode* resultHead = new ListNode(0); // useless listnode, just help to code
        ListNode* resultTmp = resultHead;
        int r = 0, c = 0;
        while(tmp1 && tmp2) {
            r = tmp1->val + tmp2->val + c;
            c = 0;
            if(r >= 10) {
                c = 1;
                r = r - 10;
            }
            resultTmp->next = new ListNode(r);
            resultTmp = resultTmp->next;
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        while(tmp1) {
            r = tmp1->val + c;
            c = 0;
            if(r >= 10) {
                c = 1;
                r = r - 10;
            }
            resultTmp->next = new ListNode(r);
            resultTmp = resultTmp->next;
            tmp1 = tmp1->next;
        }
        while(tmp2) {
            r = tmp2->val + c;
            c = 0;
            if(r >= 10) {
                c = 1;
                r = r - 10;
            }
            resultTmp->next = new ListNode(r);
            resultTmp = resultTmp->next;
            tmp2 = tmp2->next;
        }
        if(c > 0) {
            resultTmp->next = new ListNode(c);
        }
        return resultHead->next;
    }
};