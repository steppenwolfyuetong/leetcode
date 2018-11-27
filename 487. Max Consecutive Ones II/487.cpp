#include <vector>
#include <iostream>
using namespace std;

// Given a binary array, find the maximum number of consecutive 1s in this array if you can flip at most one 0.
// 找到恰好中间间隔1个0的连续"1"

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int rt = 0, a = 0, b = 0;
        for(int i = 0; i < nums.size(); i++) 
        {
            if(nums[i] == 1)
            {
                b += 1;
            }
            else
            {
                a = b;
                b = 0;
            }
            rt = max(rt, a + b + 1);
        }
        return rt;
    }
};

int main()
{
    Solution *s = new Solution();
    int array[] = {1,0,1,1,1,1,0,1};
    vector<int> nums(array, array + sizeof(array) / sizeof(int));
    cout << s->findMaxConsecutiveOnes(nums) << endl;
    return 0;
}
