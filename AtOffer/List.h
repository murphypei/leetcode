/**
* 链表定义
*/

#ifndef _LIST_H_

#define _LIST_H_

// 链表节点
struct ListNode {
	int val;
	ListNode *pNext;

	ListNode(int n)
	{
		val = n;
		pNext = nullptr;
	}
};

// 链表的操作
ListNode* CreateListNode(int value);
void ConnectListNodes(ListNode* pCurrent, ListNode* pNext);
void PrintListNode(ListNode* pNode);
void PrintList(ListNode* pHead);
void DestoryList(ListNode* pHead);
void AddToTail(ListNode **pHead, int value);
void RemoveNode(ListNode **pHead, int value);

#endif
