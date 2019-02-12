#include <vector>
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        vector<tuple<int, int, int>> preorder;          // {x, y, val}
        traverse(root, 0, 0, preorder);
        sort(preorder.begin(), preorder.end(), cmp());

        int lastx = INT_MAX;
        for (const auto& node : preorder) {
            if (get<0>(node) != lastx) {
                result.emplace_back(vector<int>());
            }
            result.back().emplace_back(get<2>(node));
            lastx = get<0>(node);
        }
        return result;
    }
private:
    void traverse(TreeNode* root, int x, int y, vector<tuple<int, int, int>>& preorder) {
        if (root == nullptr) {
            return;
        }
        preorder.emplace_back(x, y, root->val);
        traverse(root->left, x - 1, y - 1, preorder);
        traverse(root->right, x + 1, y - 1, preorder);
    }

    struct cmp {
        bool operator()(const tuple<int, int, int> &a, const tuple<int, int, int> &b) {
            if (get<0>(a) != get<0>(b)) {
                return get<0>(a) < get<0>(b);
            } else if (get<1>(a) != get<1>(b)) {
                return get<1>(a) > get<1>(b);
            } else {
                return get<2>(a) < get<2>(b);
            }
        }
    };
public:	
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

int main() {
    Solution s;
    TreeNode *root = s.createBiTree(root);
    s.verticalTraversal(root);
    return 0;
}
