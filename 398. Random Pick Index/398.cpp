#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

class Solution {
private:
    vector<int> nums;
public:
    Solution(vector<int> nums) {
        this->nums = nums;
    }

    int pick(int target) {
        int rt = -1, count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == target)
            {
                count++;
                if(count == 1)
                {
                    rt = i;
                }
                else
                {
                    if(rand() % count == 0)
                        rt = i;
                }
            }
        }
        return rt;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */

int main()
{
    int data[] = {1,2,3,3,3};
    vector<int> nums;
    for(int i = 0; i < 5; i++)
    {
        nums.push_back(data[i]);
    }

    Solution *s = new Solution(nums);
    cout << s->pick(3) << endl;
    return 0;
}
