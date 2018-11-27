#include<string>
#include<iostream>
using namespace std;


// 动态规划
// 设dp[j,i]表示[j,i]是否为回文字符串
//			 1    							(i = j)
// dp[j,i] = s[i]=s[j]  					(i = j+1)
// 			 s[i]=s[j] && dp[j+1,i-1]		(i > j+1)

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(), index = 0, maxLen = 1;
		bool dp[n][n];
		fill_n(&dp[0][0],n*n,false);
		for(int i = 0; i < n; i++)
		{
			dp[i][i] = true;
			for(int j = 0; j < i; j++)
			{
				dp[j][i] = (s[j] == s[i] && (i - j < 2 || dp[j+1][i-1]));
				if(dp[j][i] && maxLen < (i - j + 1))
				{
					maxLen = i - j + 1;
					index = j;
				}
			}
		}
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
				cout<<dp[i][j]<<' ';
			cout<<endl;
		}
		return s.substr(index,maxLen);
    }
};

int main()
{
    Solution *s = new Solution;
    string s1("wocccaccccao");
	cout<<s->longestPalindrome(s1);
}
