class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int carry = K;
        vector<int> result;
        for (int i = A.size() - 1; i > -1; i--) {
            int cur = A[i] + carry;
            result.emplace_back(cur % 10);
            carry = cur / 10;
        }

        while (carry) {
            result.emplace_back(carry % 10);
            carry /= 10;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
