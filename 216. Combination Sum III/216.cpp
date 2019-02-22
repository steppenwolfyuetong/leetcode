class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(k, n, 1, path, result);
        return result;
    }

    void dfs(int k, int n, int cur, vector<int>& path, vector<vector<int>> &result) {
        if (path.size() == k) {
            if (n == 0) {
                result.emplace_back(path);
            }
            return;
        }

        for (int i = cur; i < 10; i++) {
            if (i > n) {
                return;
            }
            path.emplace_back(i);
            dfs(k, n - i, i + 1, path, result);
            path.pop_back();
        }
    }
};
