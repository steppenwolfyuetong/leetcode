#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0), *cur = dummy;
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
		return dummy->next;
    }
	
	ListNode* createList()
    {
        int val;
        cin >> val;
        if(val == -1)
            return NULL;
        else
        {
            ListNode* pnode = new ListNode(val);
            pnode->next = createList();
            return pnode;
        }
    } 
};

int main()
{
    Solution *s = new Solution;
    ListNode *p1 = s->createList();
    ListNode *p2 = s->createList();
    ListNode *p = s->mergeTwoLists(p1,p2);
    while(p)
	{
		cout<<p->val<<' ';
		p = p->next;
	}
	cout<<endl;
    return 0;
}
