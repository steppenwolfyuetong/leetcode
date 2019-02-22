#include <string>
#include <vector>
#include <iostream>
using namespace std;

// case 2 is similar to 664
class Solution {
public:
    bool checkValidString(const string& s) {
        int n = s.length();
        if (n == 0) {
            return true;
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') {
                dp[i][i] = 1;
            }
        }

        for (int len = 2; len <= n; ++len) {
            for (int i = n - len; i > -1; i--) {                // becase we need to get dp[i+1][j-1], so iterate in reverse
                int j = i + len - 1;

                // case1: (...), *...), (...*, *...*
                if ((s[i] == '(' || s[i] == '*') && (s[j] == ')' || s[j] == '*')) {
                    if (len == 2 || dp[i + 1][j - 1]) {
                        dp[i][j] = 1;
                        continue;
                    }
                }

                // case2: find break point
                for (int k = i; k < j; k++) {
                    if (dp[i][k] && dp[k + 1][j]) {
                        dp[i][j] = 1;
                        break;
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};

int main() {
    Solution s;
    cout << s.checkValidString("(*()") << endl;
}
