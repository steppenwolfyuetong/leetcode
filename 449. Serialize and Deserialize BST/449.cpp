/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// The encoded string should be as compact as possible.
// serialize过程中 由于是BST 空节点可以不用再输出 因此题目会要求编码的string越短越好
// 直接输出先序遍历结果
// deserialize则转化为用先序遍历和中序遍历结果重建树

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialHelper(root, out);
        return out.str();
    }

    void serialHelper(TreeNode *root, ostringstream &out)
    {
        if(root != NULL)
        {
            out << root->val << ' ';
            serialHelper(root->left, out);
            serialHelper(root->right, out);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    	vector<int> preorder;
        istringstream in(data);
        string val;

        while(in >> val)
        {
            preorder.push_back(stoi(val));
        }

        vector<int> inorder(preorder);
        sort(inorder.begin(), inorder.end());
        return buildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }

    TreeNode* buildTree(vector<int> &preorder,int pstart, int pend, vector<int> &inorder, int istart, int iend)
    {
        if(pstart == pend)
            return NULL;

        TreeNode* root = new TreeNode(preorder[pstart]);
        int dis = distance(inorder.begin() + istart, find(inorder.begin() + istart, inorder.begin() + iend, root->val));
        root->left = buildTree(preorder, pstart + 1, pstart + 1 + dis, inorder, istart, istart + dis);
        root->right = buildTree(preorder, pstart + 1 + dis, pend, inorder, istart + dis + 1, iend);
        return root;
    }


public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nodes;
        preorder(root,nodes);
        return nodes;
    }

private:
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

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
//
int main()
{
    Codec *codec = new Codec();
    // string s = "4 3 2 1 7 5 6 8";
    string s = "4 3 2 7 8";
    TreeNode *root = codec->deserialize(s);
    cout << codec->serialize(root) << endl;
    vector<int> pre = codec->preorderTraversal(root);
    for(auto num : pre)
        cout << num << ' ';
    cout << endl;
    return 0;
}
