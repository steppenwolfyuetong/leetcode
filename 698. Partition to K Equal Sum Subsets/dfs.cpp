// We can figure out what target each subset must sum to. Then, let's recursively search, 
// where at each call to our function, we choose which of k subsets the next value will join.
// 
// 1 <= k <= len(nums) <= 16.
// 0 < nums[i] < 10000.

#include <vector>
#include <numeric>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (k <= 0 || total % k) {
            return false;
        }
        int target = total / k;

        sort(nums.begin(), nums.end(), greater<int>());     // sort to get better performance, 2356ms -> 16ms
        if (nums.front() > target) {
            return false;
        }
        vector<bool> used(nums.size(), false);
        return dfs(nums, target, 0, k, 0, used);
    }

    // target: target subset sum
    // cur: cur subset sum
    // groups: how many groups still need to find
    // start: next element index
    bool dfs(vector<int>& nums, int target, int cur, int groups, int start, vector<bool>& used) {
        if (groups == 0) {
            return true;
        }
        if (cur == target) {
            return dfs(nums, target, 0, groups - 1, 0, used);
        }

        for (int i = start; i < nums.size(); i++) {
            if (!used[i] && (cur + nums[i] <= target)) {
                used[i] = true;
                if (dfs(nums, target, cur + nums[i], groups, start + 1, used)) {
                    return true;
                }
                used[i] = false;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3,2,1};
    cout << s.canPartitionKSubsets(nums, 2) << endl;
}
