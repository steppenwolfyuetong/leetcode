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
 
// 1 ¡Ü m ¡Ü n ¡Ü length of list.
 
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
		if(head == NULL)
			return NULL;
		ListNode sleepy(INT_MAX);
		sleepy.next = head;
		ListNode *pre = &sleepy, *cur = head;
		bool flag = false;
		while(cur != NULL)
		{
			flag = false;
			while(cur->next != NULL && cur->val == cur->next->val)
			{
				flag = true;
				pre->next = cur->next;
				delete cur;
				cur = pre->next;
			}
			if(flag)
			{
				pre->next = cur->next;
				delete cur;
				cur = pre->next;
				continue;
			}
			pre = cur;
			cur = cur->next;
		}
        return sleepy.next;
    }
};

int main()
{
	ListNode a1(1),a2(1),a3(3),a4(4),a5(5),a6(5);	
	a1.next = &a2; a2.next = &a3; a3.next = &a4; a4.next = &a5; a5.next =&a6;
	Solution *s = new Solution;
	ListNode *head = s->deleteDuplicates(&a1);
	ListNode *cur = head;
	while(cur != NULL)
	{
		cout<<cur->val;
		cur = cur->next;
	}
}
