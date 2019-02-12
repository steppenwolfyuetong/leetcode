class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if (M.empty()) {
            return 0;
        }

        int n = M.size();
        vector<bool> visited(n, false);

        int circle = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, M, visited);
                circle++;
            }
        }
        return circle;
    }

    void dfs(int i, vector<vector<int>>& M, vector<bool> &visited) {
        visited[i] = true;
        for (int j = 0; j < visited.size(); j++) {
            if (M[i][j] == 1 && !visited[j]) {
                dfs(j, M, visited);
            }
        }
    }
};
