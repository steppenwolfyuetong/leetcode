#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        // dp[i][j] represents the number of paths from the original location to loc[i,j] by moving K steps
        vector<vector<double>> cur(vector<vector<double>>(N, vector<double>(N, 0)));
        cur[r][c] = 1.0;
        vector<vector<int>> dirs {
            vector<int>{2,1}, 
            vector<int>{1,2}, 
            vector<int>{-2,-1}, 
            vector<int>{-1,-2}, 
            vector<int>{2,-1}, 
            vector<int>{1,-2},
            vector<int>{-2,1}, 
            vector<int>{-1,2},
        };

        for (int step = 1; step <= K; step++) {
            vector<vector<double>> next(vector<vector<double>>(N, vector<double>(N, 0)));
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    for (int k = 0; k < dirs.size(); k++) {
                        int x = i + dirs[k][0];
                        int y = j + dirs[k][1];

                        if (x < 0 || x >= N || y < 0 || y >= N) {
                            continue;
                        }
                        next[x][y] += cur[i][j] / 8.0;
                    }
                }
            }
            swap(cur, next);
        }

        double result = 0;
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++) {
                result += cur[x][y];
            }
        }
        
        return result;
    }
};

int main() {
    Solution *s = new Solution();
    cout << s->knightProbability(8,30,6,4) << endl;;
    return 0;
}
