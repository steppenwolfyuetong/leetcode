/*
 * O(NlogN)
 *
 * https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
 *
 */

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
/*
The length of S will be equal to the length of the longest subsequence I've found to that point.
The last element of S will be the last element of that subsequence. 
(However, the earlier elements may no longer be part of that sequence -- S is not actually the subsequence itself.)
At the end, the length of S will be our solution.
*/
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
            if (it == res.end()) {
                res.push_back(nums[i]);
            } else {
                *it = nums[i];
            }
        }
        return res.size();
    }

    void display(vector<int> &res) {
        for (int j = 0; j < res.size(); j++) {
            cout << res[j] << " ";
        }
        cout << endl;
    }

    /*
    If we need to get the LIS instead of its length, this will work
    1. If A[i] is smallest among all end
       candidates of active lists, we will start
       new active list of length 1.
    2. If A[i] is largest among all end candidates of
      active lists, we will clone the largest active
      list, and extend it by A[i].

    3. If A[i] is in between, we will find a list with
      largest end element that is smaller than A[i].
      Clone and extend this list by A[i]. We will discard all
      other lists of same length as that of this modified list.
    */
};


int main() {
    Solution *s = new Solution();
    vector<int> nums{0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    cout << s->lengthOfLIS(nums) << endl;
    return 0;
}
