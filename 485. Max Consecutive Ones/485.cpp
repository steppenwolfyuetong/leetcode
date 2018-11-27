#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int rt = 0, curMax = 0;
        for(int i = 0; i < nums.size(); i++) 
        {
            if(nums[i] == 1)
            {
                curMax += 1;
            }
            else
            {
                rt = max(rt, curMax);
                curMax = 0;
            }
        }
        return max(rt, curMax);
    }
};

int main()
{
    Solution *s = new Solution();
    int array[] = {1,1,0,1,1,1};
    vector<int> nums(array, array + sizeof(array) / sizeof(int));
    cout << s->findMaxConsecutiveOnes(nums) << endl;
    return 0;
}
