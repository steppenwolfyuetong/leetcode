// http://zxi.mytechroad.com/blog/dynamic-programming/leetcode-730-count-different-palindromic-subsequences/

// to hard...
class Solution {
public:
    int countPalindromicSubsequences(const string& S) {
        const int n = S.length();
        cache_ = vector<vector<int>>(n, vector<int>(n, 0));
        return count(S, 0, S.length() - 1);
    }
private:
    long count(const string& str, int s, int e) {
        if (s > e) {
            return 0;
        } else if (s == e) {
            return 1;
        }

        if (cache_[s][e] > 0) {
            return cache_[s][e];
        }

        long result = 0;
        if (str[s] == str[e]) {
            // count(bccb) = 2 * count(cc) + 2
            //
            // count(cc)   = c,   cc
            // count(bccb) = bcb, bccb,
            //               b,   bb,
            int l = s + 1;
            int r = e - 1;
            while (l <= r && str[l] != str[s]) ++l;
            while (l <= r && str[r] != str[s]) --r;
            if (l > r)
                result = count(str, s + 1, e - 1) * 2 + 2;
            else if (l == r)
                result = count(str, s + 1, e - 1) * 2 + 1;
            else
                result = count(str, s + 1, e - 1) * 2 - count(str, l + 1, r - 1);
        } else {
            // count(abccb) = count(bccb) + count(abcc) - count(bcc)
            result = count(str, s + 1, e) + count(str, s, e - 1) - count(str, s + 1, e - 1);
        }

        result = (result + kMod) % kMod;
        cache_[s][e] = result;
        return result;
    }

    static constexpr long kMod = 1000000007;
    vector<vector<int>> cache_;
};
