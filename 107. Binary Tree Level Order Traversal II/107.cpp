#include<malloc.h>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode { 
    int val; 
    TreeNode *left; 
    TreeNode *right; 
    TreeNode(int x) : val(x), left(NULL), right(NULL) {} 
};

class Solution {
public:
	/*
	// µÝ¹é
	vector<vector<int> > levelOrderBottom(TreeNode* root) {
		vector<vector<int> > result;
		levelTraversal(root,1,result);
		reverse(result.begin(),result.end());
		return result;
    }
	
	void levelTraversal(TreeNode* root, int level, vector<vector<int> >& result)
	{
		if(!root)
			return;
		if(level > result.size())
			result.push_back(vector<int> ());
		result[level-1].push_back(root->val);
		levelTraversal(root->left,level+1,result);
		levelTraversal(root->right,level+1,result);
		return;
	}
	*/
	
	// ¶ÓÁÐ µü´ú
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        vector<vector<int> > result;
        if(!root)
            return result;
        queue<TreeNode*> cur, next;
        vector<int> level;
        cur.push(root);
        while(!cur.empty())
        {
            while(!cur.empty())
            {
                TreeNode *node = cur.front();
                cur.pop();
                level.push_back(node->val);
                if(node->left)
                    next.push(node->left);
                if(node->right)
                    next.push(node->right);
            }
            result.push_back(level);
            level.clear();
            swap(next,cur);
        }
		reverse(result.begin(),result.end());
        return result;
    }
	
	
    TreeNode* createBiTree(TreeNode *T)
	{
		int val;
		cin>>val;
		if(val == 0)
			return NULL;
		else
		{
			if(!(T = (TreeNode *) malloc(sizeof(TreeNode))))
				cout<<"Failure"<<endl;
			T->val = val;
			T->left = createBiTree(T->left);
			T->right = createBiTree(T->right);
			return T;
		}
	}
};

int main()
{
	Solution *s = new Solution;
	TreeNode *T = s->createBiTree(T);
	vector<vector<int> > result = s->levelOrderBottom(T);
	for(int i = 0; i < result.size(); i++)
	{
		for(int j = 0; j < result[i].size(); j++)
			cout<<result[i][j]<<' ';
		cout<<endl;
	}
	return 0;
}
