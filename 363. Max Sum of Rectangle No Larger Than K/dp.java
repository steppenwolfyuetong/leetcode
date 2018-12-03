public class Solution {
    private int[][] sum;
    private int row;
    private int col;
    public int maxSumSubmatrix(int[][] matrix, int k) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return 0;
        }
        row = matrix.length;
        col = matrix[0].length;
        sum = new int[row + 1][col + 1];
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + matrix[i - 1][j - 1] - sum[i - 1][j - 1];
            }
        }
        int max = Integer.MIN_VALUE;
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                for (int h = 0; i + h <= row ; h++) {
                    for (int w = 0; j + w <= col ; w++) {
                        int area = sum[i + h][j + w] - sum[i - 1][j + w] - sum[i + h][j - 1] + sum[i - 1][j - 1];
                        if (area > max && area <= k) {
                            max = area;
                        }
                    }
                }
            }
        }
        return max;
    }
}
