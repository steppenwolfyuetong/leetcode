class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trusts) {    
        vector<int> vote(N + 1, 0);
        vector<int> dict(N + 1, 0);
        for (const auto& kv : trusts) {
            vote[kv[0]]++;
            dict[kv[1]]++;
        }
        for (int i = 1; i <= N; i++) {
            if (vote[i] == 0 && dict[i] == N - 1) {
                return i;
            }
        }
        return -1;
    }
};
