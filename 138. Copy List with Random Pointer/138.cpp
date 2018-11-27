#include<iostream>
#include<map>
using namespace std;

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};       


// A linked list is given such that each node contains an additional random pointer 
// which could point to any node in the list or null.
// Return a deep copy of the list.

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL)
            return NULL;

        map<RandomListNode *,RandomListNode *> m;
        RandomListNode sleepy(0), *cur = head, *pre = &sleepy;
        while(cur != NULL)
        {
            RandomListNode *temp = new RandomListNode(cur->label);
            pre->next = temp;
            temp->random = cur->random;
            m[cur] = temp;
            pre = temp;
            cur = cur->next;
        }
        pre->next = NULL;

        cur = sleepy.next;
        while(cur != NULL)
        {
			if(cur->random)
				cur->random = m[cur->random];
            cur = cur->next;
        }
        return sleepy.next;
    }
};

int main()
{
	RandomListNode a1(1),a2(2),a3(3),a4(4),a5(5),a6(6);	
	a1.next = &a2; a2.next = &a3; a3.next = &a4; a4.next = &a5; a5.next =&a6;
	a1.random = &a5; a4.random = &a3; a6.random = &a6;
	Solution *s = new Solution;
	RandomListNode *head = s->copyRandomList(&a1);
	RandomListNode *cur = head;
	while(cur != NULL)
	{
		cout<<cur->label;
		cur = cur->next;
	}
}
