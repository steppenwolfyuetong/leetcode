class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        sort(A.begin(), A.end());
        int result = 0, mod = 1e9 + 7;
        for (int i = 0; i < A.size() - 2; i++) {
            int j = i + 1, k = A.size() - 1;
            while (j < k) {
                if (A[i] + A[j] + A[k] < target) {
                    j++;
                } else if (A[i] + A[j] + A[k] > target) {
                    k--;
                } else {
                    if (A[j] == A[k]) {
                        // A[j,k] are all same, so combinations is x * (x - 1) / 2, x is length of A[j,k]
                        int x = k - j + 1;
                        result = (result + x * (x - 1) / 2) % mod;
                        break;
                    }
                    
                    // count for elements equal to A[j] and A[k]
                    int c1 = 1, c2 = 1;
                    while (j + c1 < k && A[j + c1] == A[j]) {
                        c1++;
                    }
                    while (j < k - c2 && A[k - c2] == A[k]) {
                        c2++;
                    }
                    result = (result + c1 * c2) % mod;
                    j += c1;
                    k -= c2;
                }
            }
        }
        return result;
    }
};

