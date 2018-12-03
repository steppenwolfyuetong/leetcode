/*
 * implement a std::lower_bound
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int lowerbound(vector<int>& nums, int target) {
        int low = 0, high = nums.size();
        // loop invariant: with result is lower_bound(letters.begin(), letters.end(), target), low <= target <= high
        // we need to handle high = low + 1, according to the if-else statement, it won't loop forever
        while (low < high) {
            int mid = (low + high) / 2;
            if (target <= nums[mid]) {
                high = mid;                 // low can be the result
            } else if (target > nums[mid]) {
                low = mid + 1;              // mid can't be the result   
            }        
        }
        return low;
    }
};

int main() {
    Solution *s = new Solution();
    cout << "1,2,3,3,3,4,5,6,7,8" << endl;
    vector<int> nums{1,2,3,3,3,4,5,6,7,8};
    for (int i = 0; i < 12; i++) {
        cout << i << ": " << s->lowerbound(nums,i) << endl;
    }
    return 0;
}
