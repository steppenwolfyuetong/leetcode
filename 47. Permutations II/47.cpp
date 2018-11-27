#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& num) {
        sort(num.begin(),num.end());
        vector<vector<int> > result;
        vector<int> path;
		vector<bool> used(num.size(),false);
        dfs(num,used,path,result);
        return result;
    }

    void dfs(vector<int>& num, vector<bool>& used, vector<int>& path, vector<vector<int> >& result)
    {
        if(path.size() == num.size())
        {
            result.push_back(path);
            return;
        }
        for(int i = 0; i < num.size(); i++)
        {
			if(!used[i])
            {
				if(i != 0 && num[i] == num[i-1] && used[i-1])
					return;
				used[i] = true;
				path.push_back(num[i]);
				dfs(num,used,path,result);
				path.pop_back();
				used[i] = false;
			}
        }
    }
};

int main()
{
    Solution *s = new Solution;
    int arr[] = {1,1,2};
    vector<int> vec;
    for(int i = 0; i < 3; i++)
        vec.push_back(arr[i]);
    vector<vector<int> > result = s->permuteUnique(vec);
    for(int i = 0; i < result.size(); i++)
    {
        for(int j = 0; j < result[i].size(); j++)
            cout<<result[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
