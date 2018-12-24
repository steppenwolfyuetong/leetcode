/*
The main thought is:
dp[i] is the number of subseq of substring S[0 - i].

1. If S[i] is distinict from all previous chars, then dp[i] = dp[i - 1] * 2 + 1.
2. If the char in S[i] appeared at least once before S[i], then dp[i] = dp[i - 1] * 2 - repetition. 
   repetition = dp[j - 1], and j is the index the last time char in S[i] shows in S[0 - (i - 1)]. 

geeksforgeeks has a more detailed solution:
https://www.geeksforgeeks.org/count-distinct-subsequences

Tip: Because of MOD, sometimes dp[i - 1] * 2 maybe less than repetition. Then dp[i] = dp[i - 1] * 2 + MOD - repetition.

a = 1
ab = 3
abc = 7
abcc = 2 * abc - ab
*/

class Solution {
public:
    int distinctSubseqII(string S) {
        int mod = 1e9 + 7;
        vector<int> pos(26, -1), dp(S.size() + 1, 0);
        dp[0] = 1;
        
        for (int i = 1; i <= S.size(); ++i)
        {
            auto index = S[i - 1] - 'a';

            dp[i] = dp[i - 1] * 2 % mod;
            if (pos[index] != -1)
                dp[i] = (mod + dp[i] - dp[pos[index]]) % mod;       // make sure dp[i] > 0

            pos[index] = i - 1;         // store i - 1, see 2 * abc - ab
        }

        return dp[S.size()] - 1;        // remove empty string
    }
};


