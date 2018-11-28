#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int maxIndex = 0;
        int maxLen = 0;
        
        int n = s.length();
        // dp[i][j] represents if s[i,j] is palindromic substring.
        // i <= j
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 2 || dp[i+1][j-1])) {
                    dp[i][j] = true;
                    if (j - i + 1 > maxLen) {
                        maxIndex = i;
                        maxLen = j - i + 1;
                    }
                }
            }
        }
        
        return s.substr(maxIndex, maxLen);
    }
};

int main() {
    Solution *s = new Solution();
    cout << s->longestPalindrome("cbbd") << endl;
    return 0;
}
