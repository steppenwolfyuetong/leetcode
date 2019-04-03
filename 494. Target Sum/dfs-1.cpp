#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        cache = vector<vector<int>>(nums.size(), vector<int>(2001, INT_MIN));
        return helper(nums, 0, 0, S);
    }

    int helper(vector<int> &nums, int index, long sum, int target) {
        if (index == nums.size()) {
            if (sum == target)
                return 1;
            else
                return 0;
        }

        if (cache[index][sum + 1000] != INT_MIN) {
            return cache[index][sum + 1000];
        }

        int add = helper(nums, index + 1, sum + nums[index], target);
        int sub = helper(nums, index + 1, sum - nums[index], target);
        cache[index][sum + 1000] = add + sub;
        return cache[index][sum + 1000];
    }
private:
    vector<vector<int>> cache;
};

int main()
{
    Solution *s = new Solution();
    int arr[] = {1,2,3,4,5};
    int target = 3;

    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
    cout << s->findTargetSumWays(nums, target) << endl;
}
