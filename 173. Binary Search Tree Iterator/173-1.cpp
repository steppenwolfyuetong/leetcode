#include <stack>
#include <vector>
#include <iostream>
#include <malloc.h>
using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode { 
    int val; 
    TreeNode *left; 
    TreeNode *right; 
    TreeNode(int x) : val(x), left(NULL), right(NULL) {} 
};

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

//由于BST的中序遍历即为结果 iterator只需要模拟中序遍历即可
class BSTIterator {
private:
    stack<TreeNode*> nodes;
    TreeNode *cur;
public:
    BSTIterator(TreeNode *root) {
        cur = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return cur != NULL || !nodes.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *rt = NULL;
        
        if(cur == NULL)
        {
            rt = nodes.top();
            cur = nodes.top()->right;
            nodes.pop();
        }
        else
        {
            while(cur->left)
            {
                nodes.push(cur);
                cur = cur->left;
            }
            rt = cur;
            cur = cur->right;
        }
        return rt->val;
    }

};

int main()
{
	TreeNode *T = createBiTree(T);
    BSTIterator biter(T);
    while(biter.hasNext())
        cout << biter.next() << ' ';
	return 0;
}
