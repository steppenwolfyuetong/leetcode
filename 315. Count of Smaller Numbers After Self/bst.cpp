#include <vector>
#include <iostream>
using namespace std;

struct Node {
    int val;
    int count;                      // count of same value
    int leftTreeSize;               // count of smaller value
    Node *left;
    Node *right;
    Node(int x): val(x), count(1), leftTreeSize(0), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        if (nums.size() <= 1) {
            return result;
        }

        Node* root = new Node(nums.back());
        for (int i = nums.size() - 2; i > -1; i--) {
            result[i] = insert(root, nums[i]);
        }
        return result;
    }

    // return count of smaller elements
    int insert(Node* root, int value) {
        if (root->val == value) {
            root->count++;
            return root->leftTreeSize;
        } else if (root->val > value) {             // insert into root->left
            root->leftTreeSize++;
            if (root->left == nullptr) {
                root->left = new Node(value);
                return 0;                           // because only count smaller elements insert into bst later, so 0
            } else {
                return insert(root->left, value);
            }
        } else {                                    // insert into root->right
            if (root->right == nullptr) {
                root->right = new Node(value);
                return root->count + root->leftTreeSize;            // count smaller elements
            } else {
                return root->count + root->leftTreeSize + insert(root->right, value);
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {5,2,6,1};
    vector<int> result = s.countSmaller(nums);
}
