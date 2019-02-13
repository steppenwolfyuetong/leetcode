#include <map>
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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        depth(root);
        return dfs(root);
    }

private:
    TreeNode* dfs(TreeNode* root) {
        int left = depthMap_[root->left], right = depthMap_[root->right];
        if (left < right) {                 // all deepest node is in right subtree
            return dfs(root->right);
        } else if (left > right) {          // all deepest node is in left subtree
            return dfs(root->left);
        } else {
            return root;                    // return root
        }
    }

    int depth(TreeNode* root) {             // build map of <TreeNode* -> depth>
        if (root == nullptr) {
            return 0;
        }
        int left = depth(root->left), right = depth(root->right);
        int result = max(left, right) + 1;
        depthMap_[root] = result;
        return result;
    }

    map<TreeNode*, int> depthMap_;
};

// [0,2,1,null,null,3]
int main() {
    Solution s;
    TreeNode *T = s.createBiTree(T);
    cout << s.subtreeWithAllDeepest(T)->val << endl;
}
