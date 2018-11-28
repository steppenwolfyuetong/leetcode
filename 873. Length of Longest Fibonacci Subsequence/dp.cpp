#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // dp[i][j]: length of longest sequence end with A[i] and A[j], i < j
    // 
    // init value: dp[i][j] = 2
    //
    // with k < i
    // dp[i][j] = max(dp[i][j], dp[k][i] + 1 if A[j] - A[i] = A[k])
    // 
    int lenLongestFibSubseq(vector<int>& A) {
        int n = A.size();
        
        // store the index with value, so we can look-up k in table instead of iterate.
        unordered_map<int, int> table;
        for (int i = 0; i < n; i++) {
            table[A[i]] = i;
        }

        vector<vector<int>> dp(n, vector<int>(n, 2));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (table.count(A[j] - A[i])) {
                    int k = table[A[j] - A[i]];
                    if (k < i) {
                        dp[i][j] = max(dp[i][j], dp[k][i] + 1);
                    }
                }
            }
        }

        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                }
            }
        }
        return maxLen > 2 ? maxLen : 0;
    }
};

int main() {
    Solution *s = new Solution();
    vector<int> nums{1,3,7,11,12,14,18};
    cout << s->lenLongestFibSubseq(nums) << endl;
    return 0;
}
