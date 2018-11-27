#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // O(n) space
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size() < 3)
            return 0;

        // dp[i] means the number of arithmetic slices ending with A[i]
        vector<int> dp(A.size(), 0);
        if(A[2] - A[1] == A[1] - A[0])
            dp[2] = 1;

        int rt = dp[2];
        for(int i = 3; i < A.size(); i++)
        {
            // if A[i-2], A[i-1], A[i] are arithmetic, then the number of arithmetic slices ending with A[i] (dp[i])
            // equals to:
            //      the number of arithmetic slices ending with A[i-1] (dp[i-1], all these arithmetic slices appending A[i] are also arithmetic)
            //      +
            //      A[i-2], A[i-1], A[i] (a brand new arithmetic slice)
            // it is how dp[i] = dp[i-1] + 1 comes
            if(A[i] - A[i-1] == A[i-1] - A[i-2])
            {
                dp[i] = dp[i-1] + 1;
            }
            rt += dp[i];
        }
        return rt;
    }

    // O(1) space
    // just store the dp[i] with cur
    int numberOfArithmeticSlices1(vector<int>& A) {
        int cur = 0, rt = 0;
        for(int i = 2; i < A.size(); i++)
        {
            if(A[i] - A[i-1] == A[i-1] - A[i-2])
            {
                cur += 1;
                rt += cur;
            }
            else
            {
                cur = 0;
            }
        }
        return rt;
    }
};
