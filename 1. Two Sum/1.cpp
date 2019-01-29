#include<algorithm>
#include<vector>
#include<iostream>
#include<cstdlib>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
		vector<int> num = nums;
		sort(num.begin(),num.end());
		vector<int>::iterator start = num.begin();
		vector<int>::iterator end = num.end() - 1;
		while(*start + *end != target)
		{
			if(*start + *end < target)
				start++;
			else
				end--;
		}
		result.push_back(find(nums.begin(),nums.end(),*start) - nums.begin() + 1);
		result.push_back(find(nums.begin(),nums.end(),*end) - nums.begin() + 1);
		return result;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> dict;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            if (dict.count(target - nums[i])) {
                result = {i, dict[target - nums[i]]};
                return result;
            }
            dict[nums[i]] = i;
        }
        return result;
    }
};

int main()
{
	Solution *s = new Solution();
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(4);
	nums.push_back(7);
	int target = 9;
	vector<int> result = s->twoSum(nums, target);
	for(vector<int>::iterator iter = result.begin();iter < result.end();iter++)
    	cout<<*iter;
}
