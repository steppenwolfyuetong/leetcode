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

// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
// If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
// You may not alter the values in the nodes, only nodes itself may be changed.
// Only constant memory is allowed.


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)
			return head;
		if(k < 2)
			return head;
		ListNode sleepy(-1);
		sleepy.next = head;
		ListNode *pre = &sleepy,*end = head; 
        int count = 1;
		while(end != NULL)
		{
            for(count = 1; count < k && end != NULL; count++)
                end = end->next;
            if(end == NULL)
                break;
            pre = reverse(pre,pre->next,end);    
			end = pre->next;
        }
		return sleepy.next;
    }
    // pre为start前一个结点，reverse从start到end的所有节点
    // 返回翻转后的最后第一个元素
	ListNode* reverse(ListNode *pre, ListNode *start, ListNode *end)
	{
        ListNode *nextOfEnd = end->next;
		ListNode *p = start, *cur = p->next, *next = cur->next;
		while(cur != nextOfEnd)
		{
			next = cur->next;
			cur->next = p;
			p = cur;
			cur = next;
		}
		pre->next = end;
		start->next = nextOfEnd;
		return start;
	}
	
};


int main()
{
	ListNode a1(1),a2(2),a3(3),a4(4),a5(5),a6(6);	
	a1.next = &a2; a2.next = &a3; a3.next = &a4; a4.next = &a5; a5.next =&a6;
	Solution *s = new Solution;
	ListNode *head = s->reverseKGroup(&a1,3);
	//ListNode *head = s->reverse(&a1,&a2,&a5);
	ListNode *cur = head;
	while(cur != NULL)
	{
		cout<<cur->val;
		cur = cur->next;
	}
}
