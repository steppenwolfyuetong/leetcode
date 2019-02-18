// Now after pouring some non-negative integer cups of champagne, 
// return how full the j-th glass in the i-th row is (both i and j are 0 indexed.)

class Solution {
public:
    // O(n ^ 2) space
    double champagneTower(int poured, int query_row, int query_glass) {
        double result[101][101] = {0.0};            // query_row and query_glass belong to [0,99]
        result[0][0] = poured;
        for (int i = 0; i <= query_row; i++) {
            for (int j = 0; j <= i; j++) {
                if (result[i][j] >= 1) {
                    result[i+1][j] += (result[i][j] - 1) / 2;
                    result[i+1][j+1] += (result[i][j] - 1) / 2;
                    result[i][j] = 1;
                }
            }
        }
        return result[query_row][query_glass];
    }
};
