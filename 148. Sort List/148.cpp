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

// 单链表归并排序
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *p1 = head, *p2 = head;
        while(p2->next && p2->next->next)
        {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        p2 = p1->next;
        p1->next = NULL;
        p1 = head;
        p1 = sortList(p1);
        p2 = sortList(p2);
        return merge(p1,p2);
    }

    ListNode* merge(ListNode* p1, ListNode *p2)
    {
        ListNode dummy(0);
		ListNode *p = &dummy;
        for(; p1 && p2; p = p->next)
        {
            if(p1->val < p2->val)
            {
                p->next = p1;
                p1 = p1->next;
            }
            else
            {
                p->next = p2;
                p2 = p2->next;
            }
        }
        p->next = p1 ? p1 : p2;
        return dummy.next;
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
    Solution *s = new Solution();
    ListNode *head = s->createList();
    head = s->sortList(head);
    ListNode *cur = head;
    while(cur)
    {
        cout<<cur->val<<endl;
        cur = cur->next;
    }
    return 0;
}
