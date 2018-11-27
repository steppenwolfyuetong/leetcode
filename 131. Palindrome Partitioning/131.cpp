#include<vector>
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
	// dfs
    vector<vector<string> > partition(string s) {
        vector<vector<string> > result;
        vector<string> path;
        dfs(s, path, result, 0);
        return result;
    }

    void dfs(string& s, vector<string>& path, vector<vector<string> >& result, int index)
    {
        if(index == s.size())
        {
            result.push_back(path);
            return;
        }
        for(int i = index; i < s.size(); i++)
        {
            // 在i后分割
            if (isPalindrome(s,index,i))
            {
                path.push_back(s.substr(index, i - index + 1));
                dfs(s, path, result, i+1);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int start, int end)
    {
        while(start < end && s[start] == s[end])
        {
            start++;
            end--;
        }
		return start >= end;
    }
};

int main()
{
    Solution *s = new Solution;
    string a = "aab";
    vector<vector<string> > result = s->partition(a);
    for(int i = 0; i < result.size(); i++)
    {
        for(int j = 0; j < result[i].size(); j++)
            cout<< result[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
