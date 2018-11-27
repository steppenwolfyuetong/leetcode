#include<string>
#include<iostream>
using namespace std;

// 动态规划
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        bool f[m+1][n+1];
        fill_n(&f[0][0],(m+1)*(n+1),false);
        f[0][0] = true;
        for(int i = 1; i <= m; i++)
            f[i][0] = false;
        for(int j = 1; j <= n; j++)
        {
            if(j == 1)
                f[0][j] = false;
            else
                f[0][j] = p[j-1] == '*' && f[0][j-2];
        }
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(p[j-1] != '*' && p[j-1] != '.')
                {
					f[i][j] = f[i-1][j-1] && s[i-1] == p[j-1];
					continue;
				}
				if(p[j-1] == '.')
					f[i][j] = f[i-1][j-1];
				else
                    f[i][j] = f[i][j-2] || (s[i-1] == p[j-2] || p[j-2] == '.') && f[i-1][j];
            }
        }
		for(int i = 0; i <= m; i++)
		{
			for(int j = 0; j <= n ; j++)
				cout<<f[i][j]<<' ';
			cout<<endl;
		}
        return f[m][n];
    }
};

int main()
{
    Solution *s = new Solution;
    string s1("aa"),s2(".*");
	cout << s->isMatch(s1,s2) << endl;
}

