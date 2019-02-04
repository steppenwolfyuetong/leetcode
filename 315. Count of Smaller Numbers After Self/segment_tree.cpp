#include <vector>
#include <iostream>
using namespace std;

// segment tree see leetcode 307.

struct Node {                   // in segment [start, end] has `count` numbers
    int start;                  // segment node start
    int end;                    // segment node end
    int count;                  // count of numbers in this segment
    Node *left;
    Node *right;
    Node(int begin, int stop): start(begin), end(stop), count(0), left(nullptr), right(nullptr) {
        //cout << "create node " << begin << " " << end << endl;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        if (nums.size() <= 1) {
            return result;
        }

        Node *root = new Node(*min_element(nums.begin(), nums.end()), *max_element(nums.begin(), nums.end()));
        for (int i = nums.size() - 1; i > -1; i--) {
            result[i] = query(root, nums[i] - 1);           // minus 1 to exclude equal numbers
            insert(root, nums[i]);
            //cout << nums[i] << " " << result[i] << endl;
        }
        return result;
    }

    // insert into segment tree
    void insert(Node* root, int value) {
        if (root->start > value || root->end < value) {
            return;
        }

        root->count++;
        if (root->start == root->end) {
            return;
        }

        int mid = (root->start + root->end) / 2;
        if (value <= mid) {
            if (root->left == nullptr) {
                root->left = new Node(root->start, mid);
            }
            insert(root->left, value);
        } else {
            if (root->right == nullptr) {
                root->right = new Node(mid + 1, root->end);
            }
            insert(root->right, value);
        }
    }

    int query(Node* root, int value) {
        if (root == nullptr) {
            return 0;
        }

        if (value >= root->end) {
            return root->count;
        } else {
            int mid = (root->start + root->end) / 2;
            if (value <= mid) {
                return query(root->left, value);
            } else {
                return query(root->left, value) + query(root->right, value);
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {3,2,1};
    vector<int> result = s.countSmaller(nums);
}
