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
    ListNode* detectCycle(ListNode *head) {
        ListNode *p1 = head, *p2 = head;
		
        while(p2 != NULL && p2->next != NULL)
        {
			p1 = p1->next;
            p2 = p2->next->next;
            if(p1 == p2)
            {
				ListNode *p3 = head;
				while(p1 != p3)
				{
					p1 = p1->next;
					p3 = p3->next;
				}
				return p1;
			}
        }
        return NULL;
    }
};

int main()
{
	ListNode a1(1),a2(2),a3(3),a4(4),a5(5),a6(6);
	a1.next = &a2; a2.next = &a3; a3.next = &a1; //a4.next = &a5; a5.next =&a6;
	//a6.next = &a3;
	Solution *s = new Solution;
	if(ListNode *p = s->detectCycle(&a1))
		cout<<p->val<<endl;
	else
		cout<<"There is no cycle"<<endl;
	return 0;
}
