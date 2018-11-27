/*
 *
    1. The answer is between maximum value of input array numbers and sum of those numbers.
    2. Use binary search to approach the correct answer. We have l = max number of array; r = sum of all numbers in the array;Every time we do mid = (l + r) / 2;
    3. Use greedy to narrow down left and right boundaries in binary search.
        3.1 Cut the array from left.
        3.2 Try our best to make sure that the sum of numbers between each two cuts (inclusive) is large enough but still less than mid.
        3.3 We'll end up with two results: either we can divide the array into more than m subarrays or we cannot.
            If we can, it means that the mid value we pick is too small because we've already tried our best to make sure each part holds as many non-negative numbers as we can but we still have numbers left. So, it is impossible to cut the array into m parts and make sure each parts is no larger than mid. We should increase m. This leads to l = mid + 1;
            If we can't, it is either we successfully divide the array into m parts and the sum of each part is less than mid, or we used up all numbers before we reach m. Both of them mean that we should lower mid because we need to find the minimum one. This leads to r = mid - 1;
 */



#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int maxEle = 0, sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            maxEle = max(maxEle, nums[i]);
            sum += nums[i];
        }
        int low = maxEle, high = sum;
        while(low <= high)
        {
            int mid = low + ((high - low) >> 1);
            cout << low << ' ' << mid << ' ' << high << endl;
            if(valid(nums, mid, m))
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }

    //
    bool valid(vector<int>& nums, int maxSubarraySum, int subarrayCount)
    {
        int curSum = 0, count = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(curSum + nums[i] > maxSubarraySum)
            {
                count++;
                if(count > subarrayCount)
                {
                    return false;
                }
                curSum = nums[i];
            }
            else
            {
                curSum += nums[i];
            }
        }
        return true;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> nums;
    int m = 2;

    int size = 5;
    int arr[] = {7,2,5,10,8};
    for(int i = 0; i < size; i++)
    {
        nums.push_back(arr[i]);
    }

    cout << s->splitArray(nums, m) << endl;
    return 0;
}
