#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

struct TreeNode { 
    int val; 
    TreeNode *left; 
    TreeNode *right; 
    TreeNode(int x) : val(x), left(NULL), right(NULL) {} 
};

class Codec {
public:
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }

private:
    void serialize(TreeNode* root, ostringstream& out) {
        if (root) {
            out << root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        } else {
            out << "# ";
        }
    }

    TreeNode* deserialize(istringstream& in) {
        string val;
        in >> val;
        if (val == "#")
            return NULL;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
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

int main()
{
	Codec xxx;
    TreeNode* T = xxx.deserialize("1 2 # # 3 4 # # 5 # #");
    vector<int> nodes = xxx.preorderTraversal(T);
    for(int i = 0; i < nodes.size(); i++)
        cout << nodes[i] << ' ';
}

