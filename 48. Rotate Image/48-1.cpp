/*
Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]

0. init
123
456
789

1. flip over according to 258
321
654
987

2. flip over according to sub-diagonal 159
741
852
963
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mid = n % 2 ? n / 2 : n / 2 - 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= mid; j++) {
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                swap(matrix[i][j], matrix[n-j-1][n-i-1]);
            }
        }
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix{{1,2,3}, {4,5,6}, {7,8,9}};
    s.rotate(matrix);
}
