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

/*
// In place partition
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
		if(head == NULL || head->next == NULL)
			return head;
		ListNode sleepy(-1);
		sleepy.next = head;
		ListNode *cur = head, *pre = &sleepy, *index = NULL;
		while(cur != NULL)
		{
			// index保存第一个 val >= x 的前一元素指针
			if(index == NULL)
			{
				if(cur->val >= x)
					index = pre;
				pre = cur;
				cur = cur->next;
			}  
			// 找到了 >= x 的元素
			else
			{
				// 将cur放到index后
				if(cur->val < x)
				{
					pre->next = cur->next;
					cur->next = index->next;
					index->next = cur;
					index = index->next;
					cur = pre->next;
				}
				else
				{
					pre = cur;
					cur = cur->next;
				}
			}
		}
		return sleepy.next;
    }
};
*/


// Merge
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *cur = head, head1(0), head2(0);
		ListNode *p1 = &head1, *p2 = &head2;
		while(cur != NULL)
		{
			if(cur->val < x)
			{
				p1->next = cur;
				p1 = p1->next;
			}
			else
			{
				p2->next = cur;
				p2 = p2->next;
			}
			cur = cur->next;
		}
		p2->next = NULL;
		p1->next = head2.next;
		return head1.next;
    }
};



int main()
{
	ListNode a1(1),a2(4),a3(3),a4(2),a5(5),a6(2);
	//a1.next = &a2; a2.next = &a3; a3.next = &a4; a4.next = &a5; a5.next =&a6;
	Solution *s = new Solution;
	ListNode *head = s->partition(&a1,3);
	ListNode *cur = head;
	while(cur != NULL)
	{
		cout<<cur->val;
		cur = cur->next;
	}
}
