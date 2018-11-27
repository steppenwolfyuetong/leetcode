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
    ListNode* insertionSortList(ListNode* head) {
        if(!head)
            return NULL;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *cur = head, *pre = &dummy;
        while(cur != NULL)
        {
            if(cur->next && cur->next->val < cur->val)
            {
                while(pre->next && pre->next->val < cur->next->val)
                    pre = pre->next;
				// insert cur->next after pre
                ListNode *temp = pre->next;
                pre->next = cur->next;
                cur->next = cur->next->next;
                pre->next->next = temp;
                pre = &dummy;
            }
            else
                cur = cur->next;
        }
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
    head = s->insertionSortList(head);
    ListNode *cur = head;
    while(cur)
    {
        cout<<cur->val<<endl;
        cur = cur->next;
    }
    return 0;
}
