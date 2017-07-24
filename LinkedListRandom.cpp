/**
 * 设计链表的一个函数，使得每次调用能够等概率的随机返回链表中的一个节点元素
 * 蓄水池抽样法：
    * 因为不知道链表的长度，所以需要从前向后遍历。每次遍历到一个节点，假设当前遍历的节点个数（第一个节点为1）为n，用1 / n的概率替换要返回的值。
    * 可以证明，这种返回使得每个节点返回的概率是一样的
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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode *node = head;
        int cnt = 0;
        int reVal = 0;
        while(node) {
            if (rand() % (++cnt) == 0) {
                reVal = node->val;   
            }
            node = node->next;
        }
        return reVal;
    }
    
private:
    ListNode *head;
};