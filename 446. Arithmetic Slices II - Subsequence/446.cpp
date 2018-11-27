class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.empty())
            return 0;
        vector<unordered_map<int, int>> dp(A.size());   //[index, [difference, count]]

        int rt = 0;
        // subsequence end with A[i]
        for(int i = 0; i < A.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                long difference = (long)A[i] - (long)A[j];
                if(difference < INT_MIN || difference > INT_MAX)
                    continue;

                int diff = difference;

                dp[i][diff] += 1;
                if(dp[j].find(diff) != dp[j].end())
                {
                    dp[i][diff] += dp[j][diff];
                    rt += dp[j][diff];
                }
            }
        }
        return rt;
    }
};
