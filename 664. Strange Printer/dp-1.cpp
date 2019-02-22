// http://zxi.mytechroad.com/blog/dynamic-programming/leetcode-664-strange-printer/
/*
turn(s) = mininum turns to print s

turn(aabcba) = turn(aa...a) + turn(bcb)
            = turn(aa...a) + turn(b.b) + turn(c)

*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

// to hard...
class Solution {
public:
    int strangePrinter(const string& s) {
        int n = s.length();
        cache_ = vector<vector<int>>(n, vector<int>(n, 0));         // cache of turn(s[i, j])
        return turn(s, 0, s.length() - 1);
    }
private:
    // Minimal turns to print s[i] to s[j]
    int turn(const string& s, int i, int j) {
        if (i > j) return 0;
        if (cache_[i][j] > 0) return cache_[i][j];

        // Default behavior
        int ans = turn(s, i, j - 1) + 1;

        // find some break point k, so that we can print s[k] and s[j] at the same time
        // and slove the sub-problem, turn(s, i, k) and turn(s, k + 1, j - 1)
        for (int k = i; k < j; ++k)
            if (s[k] == s[j])
                ans = min(ans, turn(s, i, k) + turn(s, k + 1, j - 1));

        return cache_[i][j] = ans;
    }

    vector<vector<int>> cache_;
};

int main() {
    Solution s;
    string str = "aaabbb";
    cout << s.strangePrinter(str) << endl;
}
