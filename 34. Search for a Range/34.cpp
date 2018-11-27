#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
		vector<int>::iterator lower = searchLower(nums.begin(),nums.end(),target);
        vector<int>::iterator upper = searchUpper(nums.begin(),nums.end(),target);
        if(lower == nums.end() || *lower != target)
        {
			result.push_back(-1);
			result.push_back(-1);
		}
        else
		{
			result.push_back(lower - nums.begin());
			result.push_back(upper - 1 - nums.begin());
		}
		return result;
    }

    vector<int>::iterator searchLower(vector<int>::iterator begin, vector<int>::iterator end, int target)
    {
        while(begin < end)
        {
            vector<int>::iterator mid = begin + (end - begin) / 2;
            if(*mid < target)
                begin = mid + 1;
            else
                end = mid;
        }
        return begin;
    }

    vector<int>::iterator searchUpper(vector<int>::iterator begin, vector<int>::iterator end, int target)
    {
        while(begin < end)
        {
            vector<int>::iterator mid = begin + (end - begin) / 2;
            if(*mid <= target)
                begin = mid + 1;
            else
                end = mid;
        }
        return begin;
    }
};

int main()
{
    int arr[] = {5,7,7,8,8,10};
    vector<int> vec;
    for(int i = 0; i < 6; i++)
        vec.push_back(arr[i]);
    Solution *s = new Solution;
    vector<int> result = s->searchRange(vec,8);
    for(int i = 0; i < result.size(); i++)
        cout<<result[i]<<endl;
    return 0;
}
