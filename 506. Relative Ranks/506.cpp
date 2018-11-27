#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<int> rank;
        for(int i = 0; i < nums.size(); i++)
            rank.push_back(i);
        sort(rank.begin(), rank.end(), [&](int a, int b){return nums[a] > nums[b];});

        vector<string> result(rank.size());
        for(int index = 0; index < rank.size(); index++)
        {
            if(index == 0)
                result[rank[index]] = "Gold Medal";
            else if(index == 1)
                result[rank[index]] = "Silver Medal";
            else if(index == 2)
                result[rank[index]] = "Bronze Medal";
            else
                result[rank[index]] = to_string(index + 1);
        }

        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1};
    vector<string> result = s.findRelativeRanks(nums);
	for(auto& str : result)
		cout << str << endl;
    return 0;
}

