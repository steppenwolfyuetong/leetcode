#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.end() - k);
        reverse(nums.end() - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};


int main() {
    Solution s;
    vector<int> nums = {1, 2};
    s.rotate(nums, 0);
    for (auto num : nums) {
        cout << num;
    }
    return 0;
}
