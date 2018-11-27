#include <set>
#include <vector>
#include <iostream>
using namespace std;

// [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> result;
        vector<int> curSeq;
        dfs(nums, result, curSeq, 0);
        vector<vector<int>> rt(result.begin(), result.end());
        return rt;
    }

    void dfs(vector<int> &nums, set<vector<int>> &result, vector<int> &curSeq, int index)
    {
        if(index == nums.size())
            return;

        for(int k = index; k < nums.size(); k++)
        {
            if(curSeq.empty())
            {
                curSeq.push_back(nums[k]);
            }
            else if(nums[k] >= curSeq.back())
            {
                curSeq.push_back(nums[k]);
                result.insert(curSeq);
            }
            else
            {
                continue;
            }
            
            dfs(nums, result, curSeq, k + 1);
            curSeq.pop_back();
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums = {4,6,7,7};
    vector<vector<int>> rt = s.findSubsequences(nums);
    for(auto vec : rt)
    {
        for(auto num : vec)
        {
            cout << num << ' ';
        }
        cout << endl;
    }

    return 0;
}
