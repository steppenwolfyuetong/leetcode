class Solution {
public:
    int findMin(vector<int>& nums) {
        /*
         * invariant: min element's index i must meet left <= i <= right
         */
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            if (nums[left] < nums[right]) {
                return nums[left];
            }

            int mid = (left + right) / 2;
            if (nums[left] < nums[mid]) {
                left = mid + 1;
            } else if (nums[left] > nums[mid]) {
                right = mid;
            } else {
                left += 1;
            }
        }
        return nums[left];
    }
};
