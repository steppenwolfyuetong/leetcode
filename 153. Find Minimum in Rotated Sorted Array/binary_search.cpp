class Solution {
public:
    int findMin(vector<int>& nums) {
        /*
         * invariant: min element's index i must meet left <= i <= right
         */
        int left = 0, right = nums.size() - 1;

        // when right = left + 1, no loop forever, ok
        while (left < right) {
            if (nums[left] < nums[right]) {
                return nums[left];
            }

            int mid = (left + right) / 2;
            if (nums[left] <= nums[mid]) {  // if left = right - 1, mid = left, because nums[left] > nums[right], so left = mid + 1
                left = mid + 1;             // new range is [mid + 1, right]
            } else {
                right = mid;                // mid itself can be min element, so new range is [left, mid]
            }        
        }
        return nums[left];
    }
};
