/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }

        priority_queue<ListNode *, vector<ListNode *>, compare> q;
        for(auto l : lists) {
            if (l != nullptr) {
                q.push(l);
            }
        }

        ListNode dummy(-1);
        ListNode *cur = &dummy;
        while (!q.empty()) {
            ListNode* front = q.top();                        
            q.pop();
            if (front->next != nullptr) {
                q.push(front->next);
            }

            cur->next = front;
            cur = front;

        }
        return dummy.next;
    }

    struct compare {
        bool operator()(const ListNode* l, const ListNode* r) {
            return l->val > r->val;
        }
    };
};
