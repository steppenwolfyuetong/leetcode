/*
 * After making any number of moves, every row of this matrix is interpreted as a binary number, 
 * and the score of the matrix is the sum of these numbers.
 *
 * 1. 1000 > 0111, so left columns are more important, so flip the row until all num in first column becomes 1
 * 2. for each column left, flip the column if there are more 0 than 1.
 */

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        if (A.empty()) {
            return 0;
        }
        int m = A.size(), n = A.front().size();
        firstColumn(A, m, n);
        otherColumn(A, m, n);
        return score(A, m, n);
    }

    // all first column becomes 1
    void firstColumn(vector<vector<int>>& A, int m, int n) {
        for (int i = 0; i < m; i++) {
            if (A[i][0] == 0) {
                for (int j = 0; j < n; j++) {
                    A[i][j] ^= 1;
                }
            }
        }
    }

    // flip remaining columns
    void otherColumn(vector<vector<int>>& A, int m, int n) {
        for (int j = 1; j < n; j++) {
            int c0 = 0, c1 = 0;
            for (int i = 0; i < m; i++) {
                if (A[i][j] == 0) {
                    c0++;
                } else {
                    c1++;
                }
            }
            // c0 > c1, flip the column
            if (c0 > c1) {
                for (int i = 0; i < m; i++) {
                    A[i][j] ^= 1;
                }
            }
        }
    }

    int score(vector<vector<int>>& A, int m, int n) {
        int result = 0;
        for (int j = n - 1, weight = 1; j > -1; j--, weight *= 2) {
            for (int i = 0; i < m; i++) {
                if (A[i][j] == 1) {
                    result += weight;
                }
            }
        }
        return result;
    }
};
