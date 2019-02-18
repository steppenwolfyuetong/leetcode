// https://zxi.mytechroad.com/blog/sp/segment-tree-sp14/

struct SegmentTreeNode {
    int start, end, sum;
    SegmentTreeNode* left;
    SegmentTreeNode* right;
    SegmentTreeNode(int a, int b, int s): start(a), end(b), sum(s), left(nullptr), right(nullptr) {}
};

class NumArray {
public:
    NumArray(vector<int> nums) {
        if (!nums.empty()) {
            root_.reset(buildTree(nums, 0, nums.size() - 1));
        }
    }
    
    void update(int i, int val) {
        updateTree(root_.get(), i, val);
    }
    
    int sumRange(int i, int j) {
        return sumRange(root_.get(), i, j);
    }
private:
    SegmentTreeNode* buildTree(const vector<int> &nums, int start, int end) {
        if (start == end) {
            return new SegmentTreeNode(start, end, nums[start]);
        }
        
        int mid = (start + end) / 2;
        auto root = new SegmentTreeNode(start, end, 0);
        root->left = buildTree(nums, start, mid);
        root->right = buildTree(nums, mid + 1, end);
        root->sum = root->left->sum + root->right->sum;
        return root;
    }

    void updateTree(SegmentTreeNode* root, int index, int value) {
        if (root == nullptr) {
            return;
        }
        if (root->start == index && root->end == index) {
            root->sum = value;
            return;
        }

        int mid = (root->start + root->end) / 2;
        if (index <= mid) {
            updateTree(root->left, index, value);
        } else {
            updateTree(root->right, index, value);
        }
        root->sum = root->left->sum + root->right->sum;
    }

    int sumRange(SegmentTreeNode* root, int start, int end) {
        if (root->start == start && root->end == end) {
            return root->sum;
        }

        int mid = (root->start + root->end) / 2;
        if (end <= mid) {
            return sumRange(root->left, start, end);
        } else if (start > mid) {
            return sumRange(root->right, start, end);
        } else {
            return sumRange(root->left, start, mid) + sumRange(root->right, mid + 1, end);
        }
    }

    unique_ptr<SegmentTreeNode> root_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
