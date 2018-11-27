#include<vector> 
#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
		if(lists.size() == 0)
			return NULL;
        int len = lists.size();
		// 两两归并 减少运算量
        while(len > 1)
        {
            for(int i = 0; i < len / 2; i++)
                lists[i] = mergeTwoLists(lists[i],lists[len-1-i]);
            len = (len + 1) / 2;
        }
        return lists[0];
    }

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
    ListNode *p3 = s->createList();
    vector<ListNode*> lists;
    lists.push_back(p1);
    lists.push_back(p2);
    lists.push_back(p3);
    ListNode *p = s->mergeKLists(lists);
    while(p)
	{
		cout<<p->val<<' ';
		p = p->next;
	}
	cout<<endl;
    return 0;
}
