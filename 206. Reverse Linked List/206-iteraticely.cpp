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
		ListNode *last = NULL, *cur = head, *next = head->next;
		while(cur != NULL)
		{
			next = cur->next;
			cur->next = last;
			last = cur;
			cur = next;
		}
		
		return last;
    }
};


int main()
{
	ListNode a1(2),a2(4),a3(3),a4(5);
	a1.next = &a2; a2.next = &a3; a3.next = &a4;
	Solution *s = new Solution;
	s->reverseList(&a1);
}
