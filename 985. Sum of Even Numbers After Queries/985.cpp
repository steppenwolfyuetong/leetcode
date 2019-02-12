class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> result;
        int even = 0;
        for (const auto& num : A) {
            if (num % 2 == 0) {
                even += num;
            }
        }

        for (const auto& query : queries) {
            int value = query[0], index = query[1];
            if (A[index] % 2 == 0) {
                even -= A[index];
            }
            A[index] += value;
            if (A[index] % 2 == 0) {
                even += A[index];
            }
            result.emplace_back(even);
        }
        return result;
    }
};
