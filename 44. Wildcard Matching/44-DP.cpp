#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
		int m = s.size(), n = p.size();
		bool pre[n+1];
		fill_n(&pre[0],n+1,false);
		pre[0] = true;
		for(int j = 1; j <= n; j++)
			pre[j] = pre[j-1] && p[j-1] == '*';
		for(int i = 1; i <= m; i++)
		{
			bool cur[n+1];
			fill_n(&cur[0],n+1,false);
			for(int j = 1; j <= n; j++)
			{
				if(p[j-1] == '*')
					cur[j] = cur[j-1] || pre[j];
				else
					cur[j] = pre[j-1] && (s[i-1] == p[j-1] || p[j-1] == '?');
			}
			for(int j = 0; j <= n; j++)
				pre[j] = cur[j];
		}
		return pre[n];
    }
};

int main()
{
    Solution *s = new Solution;
//	string s1("c"),s2("*?*");
	string s1("abefcdgiescdfimde"),s2("ab*cd?i*de");
	//         ab*cd?i*de
	//         0123456789
	cout<<s->isMatch(s1,s2);
}
