#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> rt;
        // ��һ������x��ʱ�򣬽�x - 1������ȡ��
		// ֮��������飬��nums[i] > 0,��ʾû��������i + 1����� 
        for(int i = 0; i < nums.size(); i++)
        {
            int index = abs(nums[i]) - 1;
            if(nums[index] > 0)
                nums[index] = -nums[index];
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < 0)
            {
                nums[i] = -nums[i];
            }
            else
            {
                rt.push_back(i+1);
            }
        }
        return rt;
    }
};

int main()
{
    int arr[] = {4,3,2,7,8,2,3,1};
    vector<int> nums(arr, arr + 8);
    Solution *s = new Solution();
    vector<int> rt = s->findDisappearedNumbers(nums);
    for(auto num : rt)
        cout << num << endl;
    return 0;
}
