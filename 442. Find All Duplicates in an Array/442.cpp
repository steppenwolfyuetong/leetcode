// Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
// Find all the elements that appear twice in this array.
// Could you do it without extra space and in O(n) runtime?
// how...

#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // when find a number i, flip the number at position i-1 to negative. 
    // if the number at position i-1 is already negative, i is the number that occurs twice.
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> rt;
        for(int i = 0; i < nums.size(); i++)
        {
            int index = abs(nums[i]) - 1;
            if(nums[index] < 0)
            {
                rt.push_back(abs(index + 1));
            }
            nums[index] = -nums[index];
        }
        return rt;
    }
};

int main()
{
    int arr[] = {4,3,2,7,8,2,3,1};
    vector<int> nums(arr, arr + 8);
    Solution *s = new Solution();
    vector<int> rt = s->findDuplicates(nums);

    for(auto num : rt)
        cout << num << endl;
    return 0;
}
