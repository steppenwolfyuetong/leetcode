/*
 * state: dp[i][j] whether sum "j" can be gotten from first "i" numbers.
 * base case: dp[0][0] = 1; (zero number consists of sum 0 is true)
 * trasition funcion:
 * 1) do not pick the number: dp[i][j] = dp[i-1][j] (first i-1 elements has made it to j, dp[i][j] would also make it to j )
 * 2) pick the number: dp[i][j] = dp[i-1][j- nums[i]] (j is composed of the current value nums[i] and the remaining composed of other previous numbers)
 * so dp[i][j] = dp[i-1][j] || dp[i-1][j- nums[i]]
 *
 * use one dimensional array is enough.
 */

#include <vector>
#include <bitset>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    // dp
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum >> 1;

        if(sum & 1)
            return false;

        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for(auto num : nums)
        {
            for(int j = target; j >= num; j--)
            {
                dp[j] = dp[j] || dp[j - num];
            }
        }
        return dp[target];
    }

    // bitset
    bool canPartition1(vector<int>& nums) {
        const int MAX_NUM = 100;
        const int MAX_ARRAY_SIZE = 200;
        bitset<MAX_NUM * MAX_ARRAY_SIZE + 1> bits(1);
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for(auto num : nums)
        {
            bits |= bits << num;
        }

        return !(sum & 1) && bits[sum >> 1];
    }
};

int main()
{
    int arr[] = {1,5,11,5};
    vector<int> nums;
    for(int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        nums.push_back(arr[i]);
    }

    Solution *s = new Solution();
    cout << s->canPartition(nums) << endl;
    cout << s->cnaPartition1(nums) << endl;
    return 0;
}
