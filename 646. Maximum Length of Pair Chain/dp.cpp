/*
 *  sort all pairs in asc order of pair[0]
 *  dp[i] longest length ends with ith pair
 */

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), 
                [&] (const vector<int>& p1, const vector<int> &p2) {
                    if (p1[0] < p2[0]) {
                        return true;
                    } else if (p1[0] == p2[0]) {
                        return p1[1] < p2[1];
                    } else {
                        return false;
                    }
                }
        );

        vector<int> dp(pairs.size(), 1);

        for (int i = 1; i < pairs.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (pairs[j][1] < pairs[i][0]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[pairs.size() - 1];
    }

    // why sort with pair[1] can loop only once
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), 
                [&] (const vector<int>& p1, const vector<int> &p2) {
                        return a[1] < b[1] || a[1] == b[1] && a[0] < b[0];
        );
        int cnt = 0;
        vector<int>& pre = pairs[0];
        for (int i = 0; i < pairs.size(); i++) {
            if (i == 0 || pairs[i][0] > pre[1]) {
                pre = pairs[i];
                cnt++;
            }
        }
        return cnt;
    }
};
