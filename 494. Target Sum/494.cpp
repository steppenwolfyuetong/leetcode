#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        return helper(nums, 0, 0, S);
    }


    int helper(vector<int> &nums, int index, long sum, int target)
    {
        int rt = 0;
        if(index == nums.size())
        {
            if(sum == target)
                return 1;
            else
                return 0;
        }

        rt += helper(nums, index + 1, sum + nums[index], target);
        rt += helper(nums, index + 1, sum - nums[index], target);
        return rt;
    }
};

int main()
{
    Solution *s = new Solution();
    int arr[] = {1,2,3,4,5};
    int target = 3;

    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
    cout << s->findTargetSumWays(nums, target) << endl;
}
