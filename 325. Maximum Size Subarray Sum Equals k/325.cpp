/*
Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

Example 1:
Given nums = [1, -1, 5, -2, 3], k = 3,
return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)

Example 2:
Given nums = [-2, -1, 2, 1], k = 1,
return 2. (because the subarray [-1, 2] sums to 1 and is the longest)

Follow Up:
Can you do it in O(n) time?
*/

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int curSum = 0, len = 0;
        unordered_map<int, int> cache;
        for (int i = 0; i < nums.size(); i++) {
            curSum += nums[i];
            if (curSum == k) {                          // must be current longest
                len = i + 1;                        
            } else if (cache.count(curSum - k)) {       // curSum - (curSum - k) = k
                len = max(len, i - m[curSum - k]);
            } 

            if (m.count(curSum)) {
                m[curSum] = i;                          // store the end index of curSum
            }
        }
        return len;
    }
};
