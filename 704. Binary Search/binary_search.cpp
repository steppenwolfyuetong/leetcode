class Solution {
public:
    int search(vector<int>& nums, int target) {
        // invariant: if target in nums, low <= target <= high 
        int low = 0, high = nums.size() - 1; 

        // we need to handle the case when low + 1 = high, it seems fine, no loop forever
        // which comes to the case when low = high, ok, no loop forever
        // so we need low <= high
        // if not include low == high, not include all the cases
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] < target) {
                // mid can't be the target, so new range is [mid + 1, high]
                low = mid + 1;
            } else if (nums[mid] > target) {
                // mid can't be the target, so new range is [low, mid - 1]
                high = mid - 1;
            } else {
                return mid;
            }
        }

        // the invariant becomes false, target is not in nums
        return -1;
    }
};
