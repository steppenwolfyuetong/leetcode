#include<vector>
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";
        for(int i = 0; i < strs[0].size(); i++)
            for(int j = 1; j < strs.size(); j++)
                if(strs[0][i] != strs[j][i])
                    return strs[0].substr(0,i);
        return strs[0];
    }
};

int main()
{
    Solution *s = new Solution;
	vector<string> a;
	a.push_back("abcdefg");
	a.push_back("abcdef");
	a.push_back("abcde");
	cout<<s->longestCommonPrefix(a);
}
