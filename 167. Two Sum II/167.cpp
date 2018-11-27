#include <vector>
#include <iostream>
using namespace std;

//和第一题的区别是 这次的输入是已经排过序的 用两个指针维护即可
//不需要再用哈希表

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> rt(2,-1);
        int left = 0, right = numbers.size() - 1;
        while(left < right)
        {
            int temp = numbers[left] + numbers[right];
            if(temp == target)
            {
                rt[0] = left + 1;
                rt[1] = right + 1;
                return rt;
            }
            else if (temp < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return rt;
    }
};

int main()
{
    Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(4);
	nums.push_back(7);
	int target = 9;
	vector<int> result = s.twoSum(nums, target);
	for(vector<int>::iterator iter = result.begin();iter < result.end();iter++)
    	cout << *iter << ' ';
}
