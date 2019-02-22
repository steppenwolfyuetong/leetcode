class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        cache_ = vector<int>(target + 1, -1);
        cache_[0] = 1;
        return dfs(nums, target);
    }
    int dfs(vector<int>& nums, int target) {
        if (target < 0) {
            return 0;
        }
        if (cache_[target] != -1) {
            return cache_[target];
        }
        
        int result = 0;
        for (const auto& num : nums) {
            result += dfs(nums, target - num);
        }
        cache_[target] = result;
        return result;
    }

    vector<int> cache_;
};
