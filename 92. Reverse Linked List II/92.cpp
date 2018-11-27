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
 
// 1 ≤ m ≤ n ≤ length of list.
 
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode sleepy(-1);
		// 保证只有一个头结点的时候 能正常返回
		sleepy.next = head;
		ListNode *p = &sleepy;
		for(int i = 0; i < m - 1; i++)
			p = p->next;
		ListNode *prev = p->next;
		ListNode *cur = prev->next;
		for(int i = m; i < n; i++)
		{
			prev->next = cur->next;
			cur->next = p->next;
			p->next = cur;
			cur = prev->next;
		}
		return sleepy.next;
	}
};

int main()
{
	ListNode a1(1),a2(2),a3(3),a4(4),a5(5);
	//a1.next = &a2; a2.next = &a3; a3.next = &a4; a4.next = &a5;
	Solution *s = new Solution;
	ListNode *head = s->reverseBetween(&a1,1,1);
	ListNode *cur = head;
	while(cur != NULL)
	{
		cout<<cur->val;
		cur = cur->next;
	}
}
