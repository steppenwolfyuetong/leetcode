/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include<iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *cur = dummy;
        while(cur->next)
        {
            if(cur->next->val == val)
            {
                cur->next = cur->next->next;
            }
            else
            {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};



int main()
{
	ListNode a1(1),a2(2),a3(6),a4(3),a5(4),a6(5),a7(6);
	a1.next = &a2; a2.next = &a3; a3.next = &a4; a4.next = &a5; a5.next = &a6; a6.next = &a7;
	Solution *s = new Solution;
	ListNode *p = s->removeElements(&a1,6);
    while(p)
    {
        cout << p->val << ' ';
        p = p->next;
    }
	return 0;
}
