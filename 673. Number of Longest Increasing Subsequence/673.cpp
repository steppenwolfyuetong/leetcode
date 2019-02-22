#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        vector<int> dpLen(nums.size(), 1);              // length of LIS ending with nums[i]
        vector<int> dpCnt(nums.size(), 1);              // count of LIS ending with nums[i]

        for (int i = 1; i < nums.size(); i++) {         // sequence ending with nums[i]
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (dpLen[j] + 1 > dpLen[i]) {
                        dpLen[i] = dpLen[j] + 1;
                        dpCnt[i] = dpCnt[j];
                    } else if (dpLen[j] + 1 == dpLen[i]) {
                        dpCnt[i] += dpCnt[j];
                    }
                }
            }
        }

        int result = 0;
        int maxLen = *max_element(dpLen.begin(), dpLen.end());
        for (int i = 0; i < nums.size(); i++) {
            if (dpLen[i] == maxLen) {
                result += dpCnt[i];
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,3,5,4,7};
    cout << s.findNumberOfLIS(nums) << endl;
    nums = {2,2,2,2,2};
    cout << s.findNumberOfLIS(nums) << endl;
}
