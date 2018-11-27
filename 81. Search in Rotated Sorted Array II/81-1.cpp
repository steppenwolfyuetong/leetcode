// The array may contain duplicates.

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty())
            return false;
        if(nums.size() == 1)
            return nums.front() == target ? true : false;

        int low = 0, high = nums.size() - 1;
        while(low <= high)
        {
            int mid = low + ((high - low) >> 1);
            if(nums[mid] == target)
                return true;
            
            if(nums[low] == nums[mid] && nums[mid] == nums[high])
            {
                left++;
                high--;
            }
            // 判断翻转在左侧还是在右侧
            else if(nums[low] <= nums[mid])             // 翻转处在右侧
            {
                if(nums[low] <= target && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else                                       // 翻转处在左侧
            {
                if(nums[mid] < target && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return false;
    }
};
