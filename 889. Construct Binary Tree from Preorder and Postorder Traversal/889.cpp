/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 * pre: root (left subtree) (right subtree)
 * post: (left subtree) (right subtree) root
 */

class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        if (pre.empty()) {
            return nullptr;
        }
        int n = pre.size();
        int pre_start = 0, pre_end = n - 1;             // inclusive
        int post_start = 0, post_end = n - 1;           // inclusive
        TreeNode* root = build(pre, post, pre_start, pre_end, post_start, post_end);
        return root;
    }

    TreeNode* build(vector<int>& pre, vector<int>& post, int pre_start, int pre_end, int post_start, int post_end) {
        if (pre_start == pre_end) {                         // leaf node
            return new TreeNode(pre[pre_start]);
        }

        TreeNode *root = new TreeNode(pre[pre_start]);      // pre[pre_start] and post[post_end] are equal

        // left subtree root index in pre
        int left_root = pre_start + 1;
        /*
         *  we can use an unordered_set to store the index, so we don't have to find each time
         *  for (int i = 0; i < len; i++) m[post[i]] = i;
         */ 
        // find left_root in post to get length of left substree sequence
        int left_len = find(post.begin() + post_start, post.begin() + post_end + 1, pre[left_root]) - (post.begin() + post_start) + 1;
        // recursive build
        root->left = build(pre, post, 
                pre_start + 1, pre_start + left_len, 
                post_start, post_start + left_len - 1);

        // has right subtree
        if (pre_start + left_len < pre_end) {
            // right subtree root index in pre
            int right_root = pre_start + left_len + 1;
            // recursive build
            root->right = build(pre, post, 
                    pre_start + left_len + 1, pre_end,
                    post_start + left_len, post_end - 1);
        }
        return root;
    }

    // stack 
    // We will preorder generate TreeNodes, push them to stack and postorder pop them out.
    // 1. Loop on pre array and construct node one by one.
    // 2. stack save the current path of tree.
    // 3. node = new TreeNode(pre[i]), if not left child, add node to the left. otherwise add it to the right.
    // 4. If we meet a same value in the pre and post, it means we complete the construction for current subtree. We pop it from stack
    TreeNode* constructFromPrePost(vector<int> pre, vector<int> post) {
        vector<TreeNode*> s;
        s.push_back(new TreeNode(pre[0]));
        for (int i = 1, j = 0; i < pre.size(); ++i) {
            TreeNode* node = new TreeNode(pre[i]);
            while (s.back()->val == post[j]) {
                s.pop_back(), j++;
            }
            if (s.back()->left == NULL) {
                s.back()->left = node;
            } else {
                s.back()->right = node;
            }
            s.push_back(node);
        }
        return s[0];
    }

	vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nodes;
        preorder(root,nodes);
        return nodes;
    }

    void preorder(TreeNode* root, vector<int>& nodes)
    {
        if(root == NULL)
            return;
        nodes.push_back(root->val);
        preorder(root->left,nodes);
        preorder(root->right,nodes);
        return;
    }
};

int main()
{
	Solution *s = new Solution();
    vector<int> pre{1,2,4,5,3,6,7};
    vector<int> post{4,5,2,6,7,3,1};
	TreeNode *T = s->constructFromPrePost(pre, post);
	vector<int> traversal = s->preorderTraversal(T);
	for(int i = 0; i < traversal.size(); i++)
		cout<< traversal[i] <<' ';
	cout << endl;
	return 0;
}
