#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    // dp
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end(), less<int>());
        int moves = 0;
        for(int i = 1; i < nums.size(); i++)
        {
            int diff = moves + nums[i] - nums[i-1];
            nums[i] += moves;
            moves += diff;
        }
        return moves;
    }

    // math
    // adding 1 to all the elements except one is equivalent to decrementing 1 from a single element
    // the problem is simplified to find the number of decrement operations required to equalize all the elements of the given array
    int minMoves1(vector<int>& nums) {
        int rt = 0;
        int minEle = INT_MAX;
        for(auto num : nums)
        {
            minEle = min(minEle, num);
        }
        for(auto num : nums)
        {
            rt += num - minEle;
        }
        return rt;
    }
};

int main()
{
}
