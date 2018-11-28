#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*
The length of the input string will fit in range [1, 105].
The input string will only contain the character '*' and digits '0' - '9'.
*/
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int mod = 1000000007;

        // dp[i] represents ways to decode string of i
        vector<uint64_t> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = helper(s.substr(0, 1));

        /*
         *  For any string s longer than 2, we can decode either the last 2 characters as a whole or the last 1 character. 
         *  So dp[i] = dp[i-1] * f(s.substr(i - 1,1)) + dp[i-2] * f(s.substr(i - 2, 2)). 
         *  f() is the number of ways to decode a string of length 1 or 2. f()could be 0, for example f("67").
         *
         */
        for (int i = 2; i <= n; i++) {
            dp[i] = (dp[i - 1] * helper(s.substr(i - 1, 1)) + dp[i - 2] * helper(s.substr(i - 2, 2))) % mod;
        }
        return dp[n];
    }
private:
    uint64_t helper(string s) {
        if (s.size() == 1) {
            if (s[0] == '*')
                return 9;
            return s[0] == '0' ? 0 : 1;
        }

        /*
         *  four cases to decode string of size 2
         *  1. pre = *, cur = *
         *  2. pre = *, cur != * 
         *  3. pre != *, cur = *
         *  4. pre != *, cur != *
         */
        if (s == "**") {
            // 11-26, except 20 because * is '1-9'
            return 15;
        } else if (s[0] == '*') {
            if (s[1] <= '6') {
                return 2;
            } else {
                return 1;
            }
        } else if (s[1] == '*') {
            if (s[0] == '1') {
                // 1*
                return 9;
            } else if (s[0] == '2') {
                // 2*
                return 6;
            } else {
                return 0;
            }
        } else {
            if (10 <= stoi(s) && stoi(s) <= 26) {
                return 1;
            } else {
                return 0;
            }
        }
    }
};


int main() {
    Solution *s = new Solution();
    string str = "**********1111111111";
    s->numDecodings(str);
    s->wtf(str);
    return 0;
}
