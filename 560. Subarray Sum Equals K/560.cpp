/*
So if we know SUM[0, i - 1] and SUM[0, j], then we can easily get SUM[i, j]. 
To achieve this, we just need to go through the array, calculate the current sum and save number of all seen PreSum to a HashMap. 
Time complexity O(n), Space complexity O(n).
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, result = 0;
        map<int, int> preSum;
        preSum[0] = 1;          // to take into account those subarrays that begin with index 0

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (preSum.count(sum - k)) {
                result += preSum[sum - k];
            }
            preSum[sum]++;
        }
        return result;
    }
};

