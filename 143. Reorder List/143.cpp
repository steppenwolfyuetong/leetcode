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
    void reorderList(ListNode* head) {
		if(head == NULL || head->next == NULL)
            return;
        int len = 0;
        ListNode *cur = head;
        while(cur != NULL)
        {
            cur = cur->next;
            len++;
        }
        int half = len % 2 ? len / 2 + 1 : len / 2;
        int i = 1;
        cur = head;
        while(i != half)
        {
            cur = cur->next;
            i++;
        }
        ListNode *p1 = head, *p2 = cur->next;
        cur->next = NULL;
        p2 = reverseList(p2);
        cur = p2;
        while(p2 != NULL)
        {
            ListNode *temp = p2->next;
            p2->next = p1->next;
            p1->next = p2;
            p1 = p1->next->next;
            p2 = temp;
        }
	}

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
	ListNode a1(1),a2(2),a3(3),a4(4),a5(5),a6(6);	
	a1.next = &a2; a2.next = &a3; a3.next = &a4; a4.next = &a5; a5.next =&a6;
	Solution *s = new Solution;
	s->reorderList(&a1);
	ListNode *cur = &a1;
	while(cur != NULL)
	{
		cout<<cur->val;
		cur = cur->next;
	}
}
