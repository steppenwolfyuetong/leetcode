class NumArray {
public:
    NumArray(vector<int> nums) {
        sum_ = vector<int>(nums.size(), 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            sum_[i] = sum;
        }
    }
    
    // [i, j]
    int sumRange(int i, int j) {
        if (i == 0) {
            return sum_[j];
        } else {
            return sum_[j] - sum_[i - 1];
        }
    }
private:
    vector<int> sum_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
