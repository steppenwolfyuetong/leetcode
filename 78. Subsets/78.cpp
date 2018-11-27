#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
	// cur保存当前选择的数
    vector<vector<int> > subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int> > result;
        vector<int> cur;
        subsets(nums,cur,0,result);
        return result;
    }

    void subsets(vector<int>& nums, vector<int>& cur, int index, vector<vector<int> >& result)
    {
		cout<<index<<endl;
        if(index == nums.size())
        {
            result.push_back(cur);
            return;
        }
        cur.push_back(nums[index]);
        subsets(nums,cur,index+1,result);
        cur.pop_back();
        subsets(nums,cur,index+1,result);
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
