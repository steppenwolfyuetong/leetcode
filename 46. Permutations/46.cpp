#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        vector<bool> used(nums.size(), false);
        dfs(nums, used, path, result);
        return result;
    }

    void dfs(vector<int>& nums, vector<bool>& used, vector<int>& path, vector<vector<int>>& result)
    {
        if(path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(!used[i]) {
                used[i] = true;
                path.push_back(nums[i]);
                dfs(nums, used, path, result);
                used[i] = false;
                path.pop_back();
            }
        }
    }
};

int main()
{
    Solution *s = new Solution;
    vector<int> vec;
    for(int i = 1; i < 4; i++)
        vec.push_back(i);
    vector<vector<int> > result = s->permute(vec);
    for(int i = 0; i < result.size(); i++)
    {
        for(int j = 0; j < result[i].size(); j++)
            cout<<result[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
