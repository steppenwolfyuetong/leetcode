class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix.front().empty()) {
            return -1;
        }
        int m = matrix.size(), n = matrix.front().size();
        int start = 0, end = m * n - 1;                         // invariant: target is in range[start, end]

        while (start <= end) {
            int mid = (start + end) / 2;
            int row = mid / n;
            int col = mid % n;
            if (matrix[row][col] > target) {
                end = mid - 1;
            } else if (matrix[row][col] < target) {
                start = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};

