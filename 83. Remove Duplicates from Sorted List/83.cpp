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
		ListNode *cur = head->next;
		ListNode *pre = head;
		while(cur != NULL)
		{
			if(pre->val == cur->val)
			{
				pre->next = cur->next;
				delete cur;
				cur = pre->next;
			}
			else
			{
				pre = cur;
				cur = cur->next;
			}
		}
        return head;
    }
};

int main()
{
	ListNode a1(1),a2(2),a3(2),a4(4),a5(5),a6(5);
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
