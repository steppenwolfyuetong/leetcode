
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while(low <= high)
        {
            int mid = low + ((high - low) >> 1);

            if(nums[mid] == target)
                return mid;

            if(nums[low] <= nums[mid])            // 翻转处在右半边 2345601
            {
                if(nums[low] <= target && target < nums[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else                                 // 翻转处在左半边 5601234
            {
                if(nums[mid] < target && target <= nums[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};
