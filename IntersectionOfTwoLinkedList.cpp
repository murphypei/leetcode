// Write a program to find the node at which the intersection of two singly linked lists begins.


// For example, the following two linked lists:

// A:          a1 → a2
//                    ↘
//                      c1 → c2 → c3
//                    ↗            
// B:     b1 → b2 → b3

// begin to intersect at node c1.


// Notes:

// If the two linked lists have no intersection at all, return null.
// The linked lists must retain their original structure after the function returns.
// You may assume there are no cycles anywhere in the entire linked structure.
// Your code should preferably run in O(n) time and use only O(1) memory.


/**
 * 重要：双遍历的思想
 *
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            
        ListNode* nodeA = headA;
        ListNode* nodeB = headB;
        while(nodeA && nodeB) {
            if(nodeA == nodeB)
                return nodeA;
                
            nodeA = nodeA->next;
            nodeB = nodeB->next;
            
            if(!nodeA && !nodeB)
                return NULL;
            
            // 双遍历
            if(!nodeA)
                nodeA = headB;
            if(!nodeB)
                nodeB = headA;
           
        }
        return NULL;
    }
};