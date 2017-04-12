#include "List.h"

#include <iostream>

using namespace std;


ListNode* CreateListNode(int value)
{
	ListNode *pNode = new ListNode(value);

	return pNode;
}


void ConnectListNodes(ListNode* pCurrent, ListNode* pNext)
{
	if (pCurrent == nullptr)
	{
		cout << "Error to connect two nodes." << endl;
		return;
	}

	pCurrent->pNext = pNext;
}


void PrintListNode(ListNode* pNode)
{
	if (pNode == nullptr)
	{
		cout << "List node is null." << endl;
		return;
	}

	cout << "The node key is : " << pNode->val << endl;

}


void PrintList(ListNode* pHead)
{
	cout << "Start print list: \n";
	
	ListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		cout << pNode->val << "\t";
		pNode = pNode->pNext;
	}
	cout << "\nEnd print list." << endl;
}


// É¾³ýÁÐ±í
void DestoryList(ListNode* pHead)
{
	ListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		pHead = pHead->pNext;
		delete pNode;
		pNode = pHead;
	}
}


void AddToTail(ListNode **pHead, int value)
{
	ListNode *newNode = new ListNode(value);
	if (pHead == nullptr)
	{
		*pHead = newNode;
	}
	else
	{
		ListNode *pNode = *pHead;
		while (pNode->pNext != nullptr)
		{
			pNode = pNode->pNext;
		}
		pNode->pNext = newNode;
	}
}


void RemoveNode(ListNode **pHead, int value)
{
	if (pHead == nullptr || *pHead == nullptr)
	{
		cout << "List is empty." << endl;
		return;
	}

	ListNode *pToBeDetele = nullptr;

	if ((*pHead)->val == value)
	{
		pToBeDetele = *pHead;
		*pHead = (*pHead)->pNext;
	}
	else
	{
		ListNode *pNode = *pHead;
		while (pNode->pNext != nullptr && pNode->pNext->val != value)
		{
			pNode = pNode->pNext;
		}

		if (pNode->pNext != nullptr && pNode->pNext->val == value)
		{
			pToBeDetele = pNode->pNext;
			pNode->pNext = pNode->pNext->pNext;
		}
	}

	if (pToBeDetele != nullptr)
	{
		delete pToBeDetele;
		pToBeDetele = nullptr;
	}
}