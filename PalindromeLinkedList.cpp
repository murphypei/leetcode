//  QuestionEditorial Solution  My Submissions
// Total Accepted: 62437 Total Submissions: 207605 Difficulty: Easy
// Given a singly linked list, determine if it is a palindrome.

// Follow up:
// Could you do it in O(n) time and O(1) space?


#include <stack>
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if(head == NULL || head->next == NULL)
			return true;
		ListNode* slow = head;
		ListNode* fast = head;
		
		// fast到达末尾时, slow到达中间（奇偶均是）
		while(fast->next != NULL && fast->next->next != NULL) {
			slow = slow->next;
			fast = fast->next->next;
		}
		
		// 反转后半部分的链表
		slow->next = reverseList(slow->next);
		slow = slow->next;
	
		// 两部分链表比较
		while(slow != NULL) {
			if(head->val != slow->val)
				return false;
			
			head = head->next;
			slow = slow->next;
		}

		return true;
	}
	

	// O(n)时间和O(1)空间反转单链表
	ListNode* reverseList(ListNode* head) {
		
		ListNode* pre = NULL;
		ListNode* next = NULL;

		while(head != NULL) {
			next = head->next;
			head->next = pre;
			pre = head;
			head = next;
		}

		return pre;
	}

};
		
		
