/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <stack>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // use a stack to reverse linked list
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        ListNode *p1 = l1, *p2 = l2;
        while(p1 != NULL)
        {
            s1.push(p1->val);
            p1 = p1->next;
        }
        while(p2 != NULL)
        {
            s2.push(p2->val);
            p2 = p2->next;
        }

        int carry = 0, sum = 0;
        ListNode *pre = NULL, *cur = NULL;

        while(!s1.empty() || !s2.empty() || carry != 0)
        {
            sum = carry;
            if(!s1.empty())
            {
                sum += s1.top();
                s1.pop();
            }
            if(!s2.empty())
            {
                sum += s2.top();
                s2.pop();
            }

            carry = sum / 10;
            cur = new ListNode(sum % 10);
			cur->next = pre;
			pre = cur;
        }
        return cur;
    }
};


int main()
{
	ListNode a1(2),a2(4),a3(3),a4(1);
	ListNode b1(5),b2(6),b3(4);
	a1.next = &a2; a2.next = &a3; a3.next = &a4;
	b1.next = &b2; b2.next = &b3;
	Solution *s = new Solution();

	ListNode *head = s->addTwoNumbers(&a1,&b1);
    ListNode *cur = head;
    while(cur)
    {
        cout << cur->val;
        cur = cur->next;
    }
    cout << endl;
    return 0;
}

