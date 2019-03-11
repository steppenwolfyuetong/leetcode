class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        // cache[i][j] saves the largestSumOfAverages with first i element and j groups
        vector<vector<double>> cache(A.size() + 1, vector<double>(K + 1, 0));
        double sum = 0;
        for (int i = 1; i <= A.size(); i++) {
            sum += A[i - 1];
            cache[i][1] = sum / i;
        }

        return search(A.size(), K, A, cache);
    }

    double search(int count, int groups, vector<int> &A, vector<vector<double>> &cache) {
        if (cache[count][groups] > 0) {
            return cache[count][groups];
        }

        // iterator last group size n
        double sum = 0;
        for (int n = 1; count - n >= groups - 1; n++) {         // count - n must have at least (groups - 1) elements to form these groups
            sum += A[count - n];
            cache[count][groups] = max(cache[count][groups], search(count - n, groups - 1, A, cache) + sum / n);
        }
        return cache[count][groups];
    }
};
