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

// Your algorithm should use only constant space. 
// You may not modify the values in the list, only nodes itself can be changed.

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
			return head;
		ListNode sleepy(-1);
		sleepy.next = head;
		ListNode *p1 = &sleepy, *p2 = NULL, *p3 = NULL;
		while(p1->next != NULL && p1->next->next != NULL)
		{
			p2 = p1->next;
			p3 = p2->next;
			p1->next = p3;
			p2->next = p3->next;
			p3->next = p2;
			p1 = p1->next->next;
		}
		return sleepy.next;
    }
};

int main()
{
	ListNode a1(1),a2(2),a3(3),a4(4),a5(5),a6(6);	
	a1.next = &a2; a2.next = &a3; a3.next = &a4; a4.next = &a5; //a5.next =&a6;
	Solution *s = new Solution;
	ListNode *head = s->swapPairs(&a1);
	ListNode *cur = head;
	while(cur != NULL)
	{
		cout<<cur->val;
		cur = cur->next;
	}
}
