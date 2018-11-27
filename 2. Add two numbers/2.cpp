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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *cur = new ListNode(0);
		ListNode *head = cur;
		int value = 0, carry = 0;
		int i = 0;
		ListNode *p1 = l1, *p2 = l2;
		while(1)
		{
			int a = 0, b = 0;
			if(p1 == NULL && p2 == NULL)
				break;
			if(p1 != NULL)
				a = p1->val;
			if(p2 != NULL)
				b = p2->val;
			value = (a + b + carry) % 10;
			carry = (a + b + carry) / 10;
			cur->next = new ListNode(value);
			cur = cur->next;

			p1 = p1 == NULL ? NULL : p1->next;
			p2 = p2 == NULL ? NULL : p2->next;
		}
		if(carry)
			cur->next = new ListNode(carry);
//		for(cur = head->next; cur != NULL; cur = cur->next)
//			cout<<cur->val<<endl;
		return head->next;
    }
};

int main()
{
	ListNode a1(2),a2(4),a3(3),b1(5),b2(6),b3(4);
	a1.next = &a2; a2.next = &a3;
	b1.next = &b2; b2.next = &b3;
	Solution *s = new Solution;
	s->addTwoNumbers(&a1,&b1);
}

