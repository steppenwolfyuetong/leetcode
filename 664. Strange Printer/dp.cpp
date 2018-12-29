/*
The problem wants us to find the number of ways to do something without giving specific steps like how to achieve it. 
This can be a typical signal that dynamic programming may come to help.

dp[i][j] stands for the minimal turns we need for string from index i to index j.
So we have
dp[i][i] = 1: we need 1 turn to paint a single character.

Then we can iteration len from 1 to possibly n. For each iteration, we iteration start index from 0 to the farthest possible.

The maximum turns for dp[start][start + len] is len + 1, i.e. print one character each time.
We can further divide the substring to two parts: start -> start + k and start + k + 1 -> start + len. It is something as following:
index |start  ...  start + k| |start + k + 1 ... start + len|
char  |  a    ...       b   | |      c       ...      b     |

As shown above, if we have s.charAt(start + k) == s.charAt(start + len), we can make it in one turn when we print this character (i.e. b here)
This case we can reduce our turns to dp[start][start + k] + dp[start + k + 1][start + len] - 1
*/



class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        if (n == 0) {
            return 0;
        }

        vector<vector<int>> dp(n, vector<int>(n, 0)); 
        for (int k = 0; k < n; k++) {
            dp[k][k] = 1;
        }

        for (int len = 1; len < n; len++) {                             // length of print string
            for (int start = 0; start + len < n; start++) {
                dp[start][start + len] = len + 1;                       //
                for (int k = 0; k < len; k++) {                         // k is the point to seperate
                    int temp = dp[start][start + k] + dp[start + k + 1][start + len];
                    dp[start][start + len] = min(
                            dp[start][start + len], 
                            s[start + k] == s[start + len] ? temp - 1 : temp
                    );
                }
            }
        }
        return dp[0][n-1];
    }
};
