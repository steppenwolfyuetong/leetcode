#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        if (N == 0) {
            return 0;
        }
        
        vector<vector<int>> matrix(N, vector<int>(N, 1));
        for (auto& mine : mines) {
            matrix[mine[0]][mine[1]] = 0;
        }

        vector<vector<int>> dp(N, vector<int>(N, 0));
        int result = 0, count = 0;
        for (int i = 0; i < N; i++) {
            // right
            count = 0;
            for (int j = 0; j < N; j++) {
                if (matrix[i][j] == 0) {
                    count = 0;
                } else {
                    count++;
                }
                dp[i][j] = count;
            }

            count = 0;
            // left
            for (int j = N - 1; j >= 0; j--) {
                if (matrix[i][j] == 0) {
                    count = 0;
                } else {
                    count++;
                }
                dp[i][j] = min(dp[i][j], count);
            }
        }

        for (int j = 0; j < N; j++) {
            // down
            count = 0;
            for (int i = 0; i < N; i++) {
                if (matrix[i][j] == 0) {
                    count = 0;
                } else {
                    count++;
                }
                dp[i][j] = min(dp[i][j], count);
            }

            count = 0;
            for (int i = N - 1; i >= 0; i--) {
                if (matrix[i][j] == 0) {
                    count = 0;
                } else {
                    count++;
                }
                dp[i][j] = min(dp[i][j], count);
                result = max(dp[i][j], result);
            }
        }

        return result;
    }
};

int main() {
    vector<vector<int>> mines{vector<int>{0,0,0}, vector<int>{0,1,0}, vector<int>{0,0,0}};
    Solution *s = new Solution();
    cout << s->orderOfLargestPlusSign(3, mines) << endl;
    return 0;
}
