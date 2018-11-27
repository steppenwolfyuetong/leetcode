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

// �ȱ���һ�� �ó�������len ע��k���ܴ���len ����� k% = len
// ��β�ڵ�nextָ��ָ���׽ڵ㣬�γ�һ����.
// ��ͷ��㿪ʼ ������len - k �� ������Ͽ�������Ҫ��Ľ���ˡ�

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
