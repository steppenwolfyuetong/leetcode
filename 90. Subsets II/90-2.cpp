#include<set>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        set<vector<int> > ans;
		vector<int> cur;
		for(int i = 0; i < (1 << nums.size()); i++)
		{
			cout<<i<<endl;
			for(int j = 0; j < nums.size(); j++)
			{
				if(i >> j & 1)
					cur.push_back(nums[j]);
			}
			ans.insert(cur);
			cur.clear();
		}
		vector<vector<int> > result;
		result.resize(ans.size());
		copy(ans.begin(),ans.end(),result.begin());
		return result;
    }
};

int main()
{
    Solution *s = new Solution;
    int arr[] = {1,2,2};
    vector<int> vec;
    for(int i = 0; i < 3; i++)
        vec.push_back(arr[i]);
    vector<vector<int> > result = s->subsetsWithDup(vec);
    for(int i = 0; i < result.size(); i++)
    {
        for(int j = 0; j < result[i].size(); j++)
            cout<<result[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
