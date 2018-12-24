#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int start = 0, end = 0, product = 1, count = 0;
        while (end < nums.size()) {
            product *= nums[end];
            while (start <= end && product >= k) {
                product /= nums[start++];
            }
            count += end - start + 1;
            end++;
        }
        return count;
    }
};

int main() {
    Solution *s = new Solution();
    vector<int> nums{10,5,2,6};
    cout << s->numSubarrayProductLessThanK(nums, 100) << endl;
    return 0;
}

