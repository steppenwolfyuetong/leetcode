#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(),nums.end());
        vector<vector<int> > result;
        // 计算元素的个数
        vector<int> count(nums.back() - nums.front() + 1, 0);
        for(int i = 0; i < nums.size(); i++)
            count[nums[i]-nums[0]]++;
        // 每个元素选择多少个
        vector<int> used(nums.back() - nums.front() + 1, -1);
        subsetsWithDup(nums,count,used,0,result);
        return result;
    }
    
	void subsetsWithDup(vector<int>& nums, vector<int>& count, vector<int>& used, int index, vector<vector<int> >& result) 
    {
        if(index == count.size())
        {
            vector<int> cur;
            for(int i = 0; i < used.size(); i++)
                for(int j = 0; j < used[i]; j++)
                    cur.push_back(nums[0]+i);
            result.push_back(cur);
            return;
        }

        for(int i = 0; i <= count[index]; i++)
        {
            used[index] = i;
            subsetsWithDup(nums,count,used,index+1,result);
        }
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
