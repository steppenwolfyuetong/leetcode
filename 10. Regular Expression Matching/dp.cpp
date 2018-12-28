/*
 *  dp[i][j]: if s[0,i) can match p[0,j)
 *
 *  initial state:
 *      dp[0][0] = true
 *      dp[i][0] = false    i > 1
 *      dp[0][1] = false 
 *      dp[0][j] = (p[j-1] == '*' && dp[0][j-2])
 *
 *  1. p[j-1] != '.' && p[j-1] != '*'
 *      dp[i][j] = false    s[i-1] != p[j-1]
 *      dp[i][j] = true     s[i-1] == p[j-1]
 *  2. p[j-1] == '.'
 *      dp[i][j] = dp[i-1][j-1]
 *  3. p[j-1] == '*'
 *      * dp[i][j] = dp[i][j-2]             (ignore *)
 *      * s[i-1] == p[j-2] && dp[i-1][j]    (a*)
 *      * p[j-2] == '.' && dp[i-1][j]       (.*)
 */

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        dp[0][0] = true;

        for (int i = 1; i <= s.size(); i++) {
            dp[i][0] = false;
        }

        for (int j = 1; j <= p.size(); j++) {
            if (j == 1) {
                dp[0][j] = false;
            } else {
                dp[0][j] = (p[j-1] == '*' && dp[0][j-2]);
            }
        }

        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= p.size(); j++) {
                if (p[j-1] == '.') {
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j-1] == '*') {
                    dp[i][j] = dp[i][j-2] || (dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'));
                } else {
                    dp[i][j] = (dp[i-1][j-1] && s[i-1] == p[j-1]);
                }
            }
        }

        return dp[s.size()][p.size()];
    }
};

int main()
{
    Solution *s = new Solution;
    string s1("aa"),s2("a");
	cout << s->isMatch(s1,s2) << endl;
}
