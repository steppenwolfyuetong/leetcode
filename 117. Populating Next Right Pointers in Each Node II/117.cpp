#include<queue>
#include<stack>
#include<iostream>
using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	// O(n)空间可以用BFS queue实现
	/*
	void connect(TreeLinkNode *root) {
		if(!root)
			return;
		queue<TreeLinkNode*> cur,next;
		cur.push(root);
		while(!cur.empty())
		{
			while(!cur.empty())
			{
				TreeLinkNode *p = cur.front();
				cur.pop();
				if(p->left)
					next.push(p->left);
				if(p->right)
					next.push(p->right);
				p->next = cur.empty() ? NULL : cur.front();
			}
			swap(next,cur);
		}
    }
	*/
	
	// 但本题要求O(1)空间实现
	// you need to make use of the next links that you're creating.
    void connect(TreeLinkNode *root) {
		while (root) {
			TreeLinkNode * next = NULL; // the first node of next level
			TreeLinkNode * prev = NULL; // previous node on the same level
			while(root)
			{
				if (!next)
					next = root->left ? root->left : root->right;
				if (root->left) 
				{
					if (prev) 
						prev->next = root->left;
					prev = root->left;
				}
				if (root->right) 
				{
					if (prev) 
						prev->next = root->right;
					prev = root->right;
				}
				root = root->next;
			}
			root = next; // turn to next level
		}
    }
	
	vector<TreeLinkNode*> preorderTraversal(TreeLinkNode* root) {
        vector<TreeLinkNode*> nodes;
        preorder(root,nodes);
        return nodes;
    }

    void preorder(TreeLinkNode* root, vector<TreeLinkNode*>& nodes)
    {
        if(root == NULL)
            return;
        nodes.push_back(root);
        preorder(root->left,nodes);
        preorder(root->right,nodes);
        return;
    }
	
	TreeLinkNode* createBiTree(TreeLinkNode *T)
	{
		int val;
		cin>>val;
		if(val == 0)
			return NULL;
		else
		{
			TreeLinkNode *T = new TreeLinkNode(val);
			T->left = createBiTree(T->left);
			T->right = createBiTree(T->right);
			return T;
		}
	}
};

int main()
{
	Solution *s = new Solution;
	TreeLinkNode *T = s->createBiTree(T);
	s->connect(T);
	vector<TreeLinkNode*> nodes = s->preorderTraversal(T);
	for(int i = 0; i < nodes.size(); i++)
		cout<<nodes[i]->val<<' ';
	cout<<endl;
	for(int i = 0; i < nodes.size(); i++)
		if(nodes[i]->next)
			cout<<nodes[i]->next->val<<' ';
		else
			cout<<"NULL"<<' ';
	return 0;
}
