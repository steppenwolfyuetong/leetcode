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
	vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
		vector<vector<int> > result;
		levelTraversal(root,1,result,false);
		return result;
    }
	
	void levelTraversal(TreeNode* root, int level, vector<vector<int> >& result,bool flag)
	{
		if(!root)
			return;
		if(level > result.size())
			result.push_back(vector<int> ());
		if(flag == false)
			result[level-1].push_back(root->val);
		else
			result[level-1].insert(result[level-1].begin(),root->val);
		levelTraversal(root->left,level+1,result,!flag);
		levelTraversal(root->right,level+1,result,!flag);
		return;
	}
	*/
	
	
	// ¶ÓÁÐ µü´ú
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > result;
        if(!root)
            return result;
        queue<TreeNode*> cur, next;
        vector<int> level;
        cur.push(root);
		bool flag = false;
        while(!cur.empty())
        {
			cout<<flag<<endl;
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
			if(flag)
				reverse(level.begin(),level.end());
			flag = !flag;
            result.push_back(level);
            level.clear();
            swap(next,cur);
        }
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
	vector<vector<int> > result = s->zigzagLevelOrder(T);
	for(int i = 0; i < result.size(); i++)
	{
		for(int j = 0; j < result[i].size(); j++)
			cout<<result[i][j]<<' ';
		cout<<endl;
	}
	return 0;
}
