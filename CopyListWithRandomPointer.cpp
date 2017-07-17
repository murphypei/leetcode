/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */


struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        cloneList(head);
        cloneRandomPointers(head)
        return getCloneList(head);
    }
    

    // 第一步：复制链表：只复制节点值和指向下一个节点的指针（也就是普通链表的内容）。并将复制后的节点插入到当前节点和下一节点之间
    void cloneList(RandomListNode *head) {
        if (head == nullptr)
            return;
        RandomListNode *node = head;
        while(node != nullptr) {
            // 复制当前节点，并将复制的节点插入到当前节点和下一节点之间。
            RandomListNode *newNode = new RandomListNode(node->label);
            newNode->next = node->next;
            node->next = newNode;
            node = newNode->next;
        }
    }

    // 第二步：复制链表节点中的任意节点指针
    // 因为前面已经复制过了链表，所以任意节点也在原链表节点的后面，这样不用通过遍历便可以知道对于复制后的链表，任意节点的位置
    void cloneRandomPointers(RandomListNode *head) {
        RandomListNode* node = head;
        while(node != nullptr) {
            if(node->random != nullptr) {
                node->next->random = node->random->next;
            }

            node = node->next->next;
        }
    }

    void getCloneList(RandomListNode *head) {
        RandomListNode* node = head
        if (node != nullptr) {
            RandomListNode* resultHead = head->next;
            RandomListNode* resultNode = head->next;
            node->next = resultNode->next;
            node = node->next;
        }
        // 此时node和resultNode指向同一节点
        while(node != nullptr) {
            // 连接复制链表
            resultNode->next = node->next;
            resultNode->next = resultNode->next;
            
            // 连接原链表
            node->next = resultNode->next;

            node = node->next;
        }

        return resultHead;
    }
};

