/*
Given strings S and T, find the minimum (contiguous) substring W of S, so that T is a subsequence of W.

If there is no such window in S that covers all characters in T, return the empty string "". If there are multiple such minimum-length windows, return the one with the left-most starting index.

Example 1:

Input: 
S = "abcdebdde", T = "bde"

Output: "bcde"

Explanation: 
"bcde" is the answer because it occurs before "bdde" which has the same length.
"deb" is not a smaller window because the elements of T in the window must occur in order.

Note:
All the strings in the input will only contain lowercase letters.
The length of S will be in the range [1, 20000].
The length of T will be in the range [1, 100].
*/

/*
dp[i][j] start index of S, T[0, j) is subsequence of S[0, i) 

init state: empty string is substring of every string, the left most one starts at index 0
    dp[i][0] = 0

dp[i][j]:
    1) if S[i - 1] == T[j - 1]: dp[i][j] = dp[i - 1][j - 1]
    2) if S[i - 1] != T[j - 1]: dp[i][j] = dp[i - 1][j]             // S[i - 1] is useless, so use dp[i - 1][j]


*/

#include "../leetcode.h"

// still confused
class Solution {
public:
    string minWindow(string S, string T) {
        int m = S.size(), n = T.size();
        int startIndex = -1, minLen = INT_MAX;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));      // dp[i][j] = -1 means S[0, i) can't cover T[0, j)
        for (int i = 0; i <= m ; i++) {
            dp[i][0] = i;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = (S[i - 1] == T[j - 1]) ? dp[i - 1][j - 1] : dp[i - 1][j];
            }

            if (dp[i][n] != -1) {
                int len = i - dp[i][n];
                if (len < minLen) {
                    minLen = len;
                    startIndex = dp[i][n];
                }
            }
        }
        return startIndex == -1 ? "" : S.substr(startIndex, minLen);
    }
};

int main() {
    Solution s;
    string result = s.minWindow("abcdebdde", "bde");
    cout << result << endl;
}
