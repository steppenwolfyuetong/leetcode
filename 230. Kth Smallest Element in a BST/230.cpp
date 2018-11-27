#include <stack>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	Solution()
	{
		m_count = 0;
		m_num = 0;
	}
	
    // in-order traverse iterative
    int kthSmallest1(TreeNode* root, int k)
    {
        stack<TreeNode *> stk;
        TreeNode *cur = root;
        int count = 0;
        while(cur || !stk.empty())
        {
            if(cur)
            {
                stk.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = stk.top();
                stk.pop();
                count++;
                if(count == k)
                    return cur->val;
                cur = cur->right;
            }
        }
        return 0;
    }
    
    // in-order traverse recursive
    int kthSmallest2(TreeNode* root, int k)
    {
    	m_count = 0;
    	m_num = 0;
        inorder(root,k);
        return m_num;
    }

    void inorder(TreeNode *root,int k)
    {
        if(!root)
            return;
        inorder(root->left,k);
        m_count++;
        if(m_count == k)
        {
            m_num = root->val;
            return;
        }
        inorder(root->right,k);
    }

	TreeNode* createBiTree(TreeNode *T)
	{
		int val;
		cin >> val;
		if(val == 0)
			return NULL;
		else
		{
			TreeNode *T = new TreeNode(val);
			T->left = createBiTree(T->left);
			T->right = createBiTree(T->right);
			return T;
		}
	}
private:
    int m_count;
    int m_num;
};

int main()
{
    Solution s;
    TreeNode *T = s.createBiTree(T);
    cout << s.kthSmallest1(T,3) << endl;
    cout << s.kthSmallest2(T,3) << endl;
    cout << s.kthSmallest1(T,5) << endl;
    cout << s.kthSmallest2(T,5) << endl;
}
