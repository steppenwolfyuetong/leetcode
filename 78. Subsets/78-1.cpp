#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
	// used代表是否选择某位数
    vector<vector<int> > subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int> > result;
        vector<bool> used(nums.size(),false);
        subsets(nums,used,0,result);
        return result;
    }

    void subsets(vector<int>& nums, vector<bool>& used, int index, vector<vector<int> >& result)
    {
        if(index == nums.size())
        {
            vector<int> path;
            for(int i = 0; i < used.size(); i++)
                if(used[i])
                    path.push_back(nums[i]);
            result.push_back(path);
			return;
        }
        used[index] = true;
        subsets(nums,used,index+1,result);
        used[index] = false;
        subsets(nums,used,index+1,result);
    }
};

int main()
{
    Solution *s = new Solution;
    int arr[] = {1,2,3};
    vector<int> vec;
    for(int i = 0; i < 3; i++)
        vec.push_back(arr[i]);
    vector<vector<int> > result = s->subsets(vec);
    for(int i = 0; i < result.size(); i++)
    {
        for(int j = 0; j < result[i].size(); j++)
            cout<<result[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
