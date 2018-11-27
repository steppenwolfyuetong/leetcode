#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        vector<int> path;
        dfs(n,k,1,path,result);
        return result;
    }

    void dfs(int n, int k, int start, vector<int>& path, vector<vector<int> >& result)
    {
        if(path.size() == k)
        {
            result.push_back(path);
			// cout<<'!'<<' '<<path[0]<<' '<<path[1]<<endl;
            return;
        }
		// cout<<start<<endl;
        for(int i = start; i <= n; i++)
        {
            path.push_back(i);
            dfs(n,k,i+1,path,result);
            path.pop_back();
        }
    }
};

int main()
{
    Solution *s = new Solution;
    vector<vector<int> > result = s->combine(4,2);
    for(int i = 0; i < result.size(); i++)
    {
        for(int j = 0; j < result[i].size(); j++)
            cout<<result[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
