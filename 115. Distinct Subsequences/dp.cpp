/*

    dp[i][j]: number of distinct subsequences of s[0:i) which equals t[0:j).
    ans: dp[s.size()][t.size()], number of distinct subsequences of s which equals t.
    initial state: 
        dp[i][0] = 1    (when t is empty string, any string can match it)
        dp[0][j] = 0    (j > 0, when s is empty string and t is not empty, cannot match)
    transfer:
        1. s[i - 1] != t[j - 1]
            dp[i][j] = dp[i-1][j]

            if s[i-1] != t[j-1], distinct sbsequences will not include s[i-1], 
            so the result is the  distinct subsequences will simply be those between s[0:i-1) and t[0:j), which is dp[i-1][j]

        2. s[i - 1] == t[j - 1]
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1] 

            if s[i-1] != t[j-1], distinct sbsequences may or may not include s[i-1], 
            if not included, which is same as case 1, dp[i-1][j]
            if included, whichi is dp[i-1][j-1]


for example, s = abbc, t = abc

        a   b   c
    1   0   0   0
a   1   1   0   0
b   1   1   1   0
b   1   1   2   0
c   1   1   2   2
*/


#include <vector>
#include <string>
#include <iostream>
using namespace std;


class Solution {
public:
    /*
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));        

        for (int i = 0; i < s.size(); i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                if (s[i-1] != t[j-1]) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                }
            }
        }
        return dp[s.size()][t.size()];
    }
    */

    // we only need previous row, so no need to use O(MN) space, O(M) space is enough
    int numDistinct(string s, string t) {
        vector<int> dp(t.size() + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= s.size(); i++) {
            for (int j = t.size(); j >= 1; j--) {
                if (s[i-1] == t[j-1]) {
                    dp[j] = dp[j] + dp[j-1];
                }
            }
        }
        return dp[t.size()];
    }
};

int main() {
    Solution *s = new Solution();
    cout << s->numDistinct("rabbbit", "rabbit") << endl;
    return 0;
}
