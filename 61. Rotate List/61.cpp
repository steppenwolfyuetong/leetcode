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

// 先遍历一遍 得出链表长度len 注意k可能大于len 因此令 k% = len
// 将尾节点next指针指向首节点，形成一个环.
// 从头结点开始 往后跑len - k 步 从这里断开，就是要求的结果了。

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
		if(head == NULL || head->next == NULL)
			return head;
        int len = 1;
		ListNode *cur = head;
		while(cur->next != NULL)
		{
			cur = cur->next;
			len++;
		}
		k %= len;
		cur->next = head;
		cur = head;
		for(int i = 0; i != len - k - 1; i++, cur = cur->next)
			;
		ListNode *result = cur->next;
		cur->next = NULL;
		return result;
    }
};

int main()
{
	ListNode a1(1),a2(2),a3(3),a4(4),a5(5),a6(6);	
	a1.next = &a2; a2.next = &a3; a3.next = &a4; a4.next = &a5; //a5.next =&a6;
	Solution *s = new Solution;
	ListNode *head = s->rotateRight(&a1,2);
	ListNode *cur = head;
	while(cur != NULL)
	{
		cout<<cur->val;
		cur = cur->next;
	}
}
