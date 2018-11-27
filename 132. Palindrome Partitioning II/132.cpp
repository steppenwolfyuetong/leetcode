#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int minCut(string s) {
		const int size = s.size();
		if(size == 1)
			return 0;
		bool p[size+1][size+1];
		fill_n(&p[0][0],(size+1)*(size+1),false);
		int dp[size+1];
		for(int i = 0; i < size + 1; i++)
			dp[i] = i - 1;
		for(int i = 1; i <= size; i++)
		{
			for(int j = 1; j <= i; j++)
			{
				// Ë÷Òý-1
				if(s[i-1] == s[j-1])
					if(i - j < 2 || p[j+1][i-1])
					{
						p[j][i] = true;
						if(dp[j-1] + 1 < dp[i])
							dp[i] = dp[j-1] + 1;
					}
			}
		}
		return dp[size];
    }
};

int main()
{
	Solution *s = new Solution;
	string str = "abaabbabba";
	cout<<s->minCut(str)<<endl;
}
