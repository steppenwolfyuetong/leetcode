#include <vector>
#include <iostream>
#include <functional>
using namespace std;

class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        int result = 0;
        int mod = 1000000007;
        
        vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(m, vector<int>(n,0)));
        dp[0][i][j] = 1;
        vector<vector<int>> dirs{vector<int>{1,0}, vector<int>{-1,0}, vector<int>{0,1}, vector<int>{0,-1}};

        for (int step = 1; step <= N; step++) {
            for (int x = 0; x < m; x++) {
                for (int y = 0; y < n; y++) {
                    if (dp[step - 1][x][y]) {
                        for (int k = 0; k < dirs.size(); k++) {
                            int xx = x + dirs[k][0];
                            int yy = y + dirs[k][1];

                            if (xx < 0 || xx >= m || yy < 0 || yy >= n) {
                                result = (result + dp[step - 1][x][y]) % mod;
                            } else {
                                dp[step][xx][yy] = (dp[step][xx][yy] + dp[step - 1][x][y]) % mod;
                            }
                        }
                    }
                }
            }
        }

        return result;
    }
};

int main() {
    Solution *s = new Solution();
    cout << s->findPaths(3, 3, 3, 1, 1) << endl;
    return 0;
}
