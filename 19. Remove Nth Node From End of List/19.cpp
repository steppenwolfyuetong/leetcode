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


// Given n will always be valid.
// Try to do this in one pass

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)
			return head;
		ListNode sleepy(0);
		sleepy.next = head;
		ListNode *p1 = head, *p2 = head, *p3 = &sleepy;
		// p1指向头结点 p2指向第n个结点
		// 使p1,p2同时向结尾迭代 当p2指向尾结点时 p1就指向倒数第n个结点
		for(int i = 1; i != n; i++, p2 = p2->next);
		while(p2->next != NULL)
		{
			// p3保存要删除结点的前结点
			p3 = p1;
			p1 = p1->next;
			p2 = p2->next;
		}
		//删除p1指向的结点
		p3->next = p1->next;
		delete p1;
		return sleepy.next;
    }
};


int main()
{
	ListNode a1(1),a2(2),a3(3),a4(4),a5(5),a6(6);	
	a1.next = &a2; a2.next = &a3; a3.next = &a4; a4.next = &a5; a5.next =&a6;
	Solution *s = new Solution;
	ListNode *head = s->removeNthFromEnd(&a1,6);
	ListNode *cur = head;
	while(cur != NULL)
	{
		cout<<cur->val;
		cur = cur->next;
	}
}
