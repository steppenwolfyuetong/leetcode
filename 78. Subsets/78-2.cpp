#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    // 二进制法
    // 用一个二进制数代表是否选择
    vector<vector<int> > subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int> > result;
        vector<int> cur;
        for(int i = 0; i < 1 << nums.size(); i++)
        {
            for(int j = 0; j < nums.size(); j++)
                if((i >> j) & 1)
                    cur.push_back(nums[j]);
            result.push_back(cur);
            cur.clear();
        }
        return result;
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
