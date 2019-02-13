// Either product of 3 biggest positive values will be maxProduct or 
// if there are negative values then pick the 2 biggest negative values and multiply with biggest positive value
//
// Sort the Array and compare above mentioned products

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if (nums.size() < 3) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int temp1 = nums[n-1] * nums[n-2] * nums[n-3];
        int temp2 = nums[0] * nums[1] * nums[n-1];
        return temp1 > temp2 ? temp1 : temp2;
    }
};

// Instead of sorting you can probably look for the first three maximum and first two minimum elements in O(n). 
// And follow the same logic.


