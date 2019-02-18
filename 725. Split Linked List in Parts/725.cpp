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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int length = 0;
        ListNode* cur = root;
        ListNode* pre = nullptr;
        while (cur) {
            cur = cur->next;
            length++;
        }

        vector<ListNode*> result(k, nullptr);
        int avg = length / k, rem = length % k;
        cur = root;
        for (int i = 0; cur && i < k; i++) {
            result[i] = cur;
            for (int j = 0; j < avg; j++) {
                pre = cur;
                cur = cur->next;
            }
            if (rem) {
                pre = cur;
                cur = cur->next;
                rem--;
            }
            pre->next = nullptr;
        }
        return result;
    }
};
