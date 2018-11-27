#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int minCut(string s) {
		const int size = s.size();
		if(size == 1)
			return 0;
		bool p[size][size];
		fill_n(&p[0][0],size*size,false);

		int dp[size+1];
		for(int i = 0; i <= size; i++)
			dp[i] = size - i - 1;

		for(int i = size - 1; i >= 0; i--)
		{
			for(int j = i; j < size; j++)
			{
				if(s[i] == s[j])
					if(j - i < 2 || p[i+1][j-1])
					{
						p[i][j] = true;
						dp[i] = dp[i] < dp[j+1] + 1 ? dp[i] : dp[j+1] + 1;
					}
			}
		}
		cout<<dp[0];
		return dp[0];
    }
};


int main()
{
	Solution *s = new Solution;
	string str = "abaabbabba";
	s->minCut(str);
}
