#include <iostream>
using namespace std;

class Solution {
public:
    int numTilings(int N) {
        if (N == 1)
            return 1;
        if (N == 2)
            return 2;
        if (N == 3)
            return 5;

        int mod = 1000000007;
        int c1 = 1, c2 = 2, c3 = 5;
        int result = 0;

        for (int i = 4; i <= N; i++) {
            result = ((2 * c3) % mod + c1) % mod; 
            c1 = c2;
            c2 = c3;
            c3 = result;
        }
        return result;
    }
};

int main() {
    Solution *s = new Solution();
    cout << s->numTilings(4) << endl;
    return 0;
}


/*
dp[i] = 2*dp[i-1] + dp[i-3] (i >= 3)

dp[n] = dp[n-1]+dp[n-2]+ 2*(dp[n-3]+...+d[0])
= dp[n-1]+dp[n-2]+dp[n-3]+dp[n-3]+2*(dp[n-4]+...+d[0])
= dp[n-1]+dp[n-3]+(dp[n-2]+dp[n-3]+2*(dp[n-4]+...+d[0]))
= dp[n-1]+dp[n-3]+dp[n-1]
= 2*dp[n-1]+dp[n-3]
*/
