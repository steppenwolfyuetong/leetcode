/*
 *
 * start from the very leftmost (the first column) till the end
 * try each width till the very rightmost (the last column)
 * calculate the prefix-sum for each row then the partial sum can be easily retrieved as one-dimension situation
 * from the top to the bottom, collect the prefix-sum of each row then we can get the prefix-sum of the rectangle
 * use a set to store the prefix-sum of the rectangles and then searching curSum-k via lower_bound to retrieve so-called Max Sum of Rectangle No Larger Than K; as a result the whole time cost will be O(n^3*logn) now instead of O(n^4)
 */

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty() || matrix.front().empty()) {
            return 0;
        }

        int m = matrix.size(), n = matrix.front().size();
        int result = INT_MIN;

        for (int start = 0; start < n; start++) {
            vector<int> rowSum(m, 0);                   // store the row sum of each row with range of [start, end]
            for (int end = start; end < n; end++) {
                for (int i = 0; i < m; i++) {
                    rowSum[i] += matrix[i][end];
                }
                
                set<int> cache;
                cache.insert(0);
                int localMax = INT_MIN, sum = 0;
                
                // add-up each row sum, to check if there is a bigger som
                for (int i = 0; i < m; i++) {
                    sum += rowSum[i];
                    auto iter = cache.lower_bound(sum - k);
                    if (iter != cache.end()) {
                        localMax = max(localMax, sum - *iter);
                    }
                    cache.insert(sum);
                }
                result = max(result, localMax);
                if (result == k) {
                    return result;
                }
            }
        }
        return result;
    }
};
