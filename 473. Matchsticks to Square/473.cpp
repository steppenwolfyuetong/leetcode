#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if(nums.empty() || nums.size() < 4)
            return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 4 != 0)
            return false;
        vector<int> length(4, 0);

        // 不添加这句会超时
        // 按照降序排列，可以使边长尽可能早的接近sum / 4
        // dfs函数中会尽快过滤
        sort(nums.begin(), nums.end(), greater<int>());

        return dfs(nums, 0, length, sum / 4);
    }

    // 遍历每一根火柴棍，并添加至某一个边上，当所有火柴棍都用完后，检查四个边是否相等
    // index:当前要添加的火柴棍
    // len:四个边当前长度
    bool dfs(vector<int> &nums, int index, vector<int> &length, int target)
    {
        if(index == nums.size())
        {
            for(auto len : length)
            {
                if(len != target)
                {
                    return false;
                }
            }
            return true;
        }

        for(int i = 0; i < length.size(); i++)
        {
            if(length[i] + nums[index] > target)
                continue;
            length[i] += nums[index];
            if(dfs(nums, index + 1, length, target))
                return true;
            length[i] -= nums[index];
        }
        return false;
    }
};

int main()
{
    Solution *s = new Solution();
    int arr[] = {3,3,3,3,4};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
    cout << s->makesquare(nums) << endl;
    return 0;
}
