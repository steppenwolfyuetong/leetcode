#include<iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
			return head;
		ListNode *next = head->next;
		// 断开所有连接
		head->next = NULL;
		ListNode *reverseHead = reverseList(next);
		// 重新反向连接
		next->next = head;
		return reverseHead;
    }
};


int main()
{
	ListNode a1(2),a2(4),a3(3),a4(5);
	a1.next = &a2; a2.next = &a3; a3.next = &a4;
	Solution *s = new Solution;
	ListNode *head = s->reverseList(&a1), *cur = head;
	while(cur != NULL)
	{
		cout<<cur->val;
		cur = cur->next;
	}
	return 0;
}
