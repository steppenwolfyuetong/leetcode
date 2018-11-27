#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& num) {
        sort(num.begin(),num.end());
        vector<vector<int> > result;
        vector<int> cur;
        dfs(num,cur,result);
        return result;
    }

    void dfs(vector<int>& num, vector<int>& cur, vector<vector<int> >& result)
    {
        if(cur.size() == num.size())
        {
            result.push_back(cur);
            return;
        }
        for(int i = 0; i < num.size(); i++)
        {
            vector<int>::iterator iter = find(cur.begin(),cur.end(),num[i]);
            if(iter == cur.end())
            {
                cur.push_back(num[i]);
                dfs(num,cur,result);
                cur.pop_back();
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
