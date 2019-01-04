/*
 * Traverse from the back to the beginning of the array, maintain an sorted array of numbers have been visited. 
 * Use lower_bound() to find the first element in the sorted array which is larger or equal to target number. 
 * For example, [5,2,3,6,1], when we reach 2, we have a sorted array[1,3,6], findIndex() returns 1, 
 * which is the index where 2 should be inserted and is also the number smaller than 2. 
 * Then we insert 2 into the sorted array to form [1,2,3,6].
 */

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result(nums.size(), 0), sorted;
        for (int i = nums.size() - 1; i > -1; i--) {
            int index = lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin();
            sorted.insert(sorted.begin() + index, nums[i]);
            result[i] = index;
        }
        return result;
    }
};
