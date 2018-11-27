#include<vector>
#include<iostream>
using namespace std;

class Solution {
public: 
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size(); 
        for (int i = 0; i < n; i++)
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);
        for (int i = 0; i < n; i++)
            if (nums[i] != i + 1)
                return i + 1;
        return n + 1;
    }
};

int main()
{
	vector<int> vec;
	int arr[4] = {3,4,-1,1};
	for(int i = 0; i < 4; i++)
		vec.push_back(arr[i]);
	Solution *s = new Solution;
	cout<<s->firstMissingPositive(vec)<<endl;
}
