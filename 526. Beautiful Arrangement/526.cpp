class Solution {
    int count = 0;
public:
    int countArrangement(int N) {
        vector<bool> used(N + 1, false);
        dfs(N, 1, used);
        return count;
    }

    void dfs(int n, int pos, vector<bool> &used) {
        if (pos > n) {
            count++;
            return;
        }

        for (int i = 1; i <= n; i++) {
            if (!used[i]) {
                if (pos % i == 0 || i % pos == 0) {
                    used[i] = true;
                    dfs(n, pos + 1, used);
                    used[i] = false;
                }
            }
        }
    }
};
