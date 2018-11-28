#include <vector>
#include <iostream>
#include <functional>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> result;
        if (nums.empty()) {
            return result;
        }

        sort(nums.begin(), nums.end(), less<int>());
        vector<int> dp(nums.size(), 1);        
        vector<int> pre(nums.size(), -1);

        int maxSize = 1;
        int maxIndex = 0;

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0;  j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    pre[i] = j;
                    if (dp[i] > maxSize) {
                        maxSize = dp[i];
                        maxIndex = i;
                    }
                }
            }
        }

        for (int i = 0; i < maxSize; i++) {
            result.push_back(nums[maxIndex]);
            maxIndex = pre[maxIndex];
        }

        return result;
    }
};

int main() {
    Solution *s = new Solution();
    vector<int> nums{1,2,3,4,5,6,7,8};
    for (auto& result : s->largestDivisibleSubset(nums)) {
        cout << result;
    }
    return 0;
}
