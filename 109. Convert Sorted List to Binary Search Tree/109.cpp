#include<vector>
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return sortedListToBST(head,NULL);        
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

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        inorder(root,nodes);
        return nodes;
    }
    
    void inorder(TreeNode* root, vector<int>& nodes)
    {
        if(root == NULL)
            return;
        inorder(root->left,nodes);
        nodes.push_back(root->val);
        inorder(root->right,nodes);
        return;
    }

private:
    TreeNode* sortedListToBST(ListNode* head, ListNode* tail)
    {
        if(head == tail)
            return NULL;
        if(head->next == tail)
        {
            TreeNode *root = new TreeNode(head->val);
            return root;
        }
        ListNode *mid = head, *dummy = head;
        while(dummy != tail && dummy->next != tail)
        {
            mid = mid->next;
            dummy = dummy->next->next;
        }
        TreeNode *root = new TreeNode(mid->val);
        root->left = sortedListToBST(head,mid);
        root->right = sortedListToBST(mid->next,tail);
        return root;
    }
};

int main()
{
    Solution *s = new Solution;
    ListNode *head = s->createList();
    TreeNode *root = s->sortedListToBST(head);
    vector<int> traversal = s->inorderTraversal(root);
    for(int i = 0; i < traversal.size(); i++)
        cout<<traversal[i];
    cout<<endl;
    return 0;
}
