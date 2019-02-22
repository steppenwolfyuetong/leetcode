#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /*
    // O(NK) time, O(1) space
    int minKBitFlips(vector<int>& A, int K) {
        int result = 0;
        for (int i = 0; i <= A.size() - K; ++i) {
            if (A[i] == 0) {
                for (int j = 0; j < K; ++j) {
                    A[i + j] ^= 1;
                }
                result++;
            }
        }
        for (int i = A.size() - K + 1; i < A.size(); ++i) {
            if (A[i] == 0) {
                return -1;
            }
        }
        return result;
    }
    */

    /*
    Create a new array isFlipped[n].
    isFlipped[i] = 1 if we flip K consecutive bits starting at A[i].

    We maintain a variable flipped and flipped = 1 if the current bit is flipped.
    If flipped = 0 and A[i] = 0, we need to flip at A[i].
    If flipped = 1 and A[i] = 1, we need to flip at A[i].
    */
    // O(N) time, O(N) space
    int minKBitFlips(vector<int>& A, int K) {
        int n = A.size(), flipped = 0, result = 0;
        vector<int> isFlipped(n, 0);
        for (int i = 0; i < A.size(); i++) {
            if (i >= K) {
                flipped ^= isFlipped[i - K];
            }
            if (flipped == A[i]) {
                if (i + K > A.size()) {
                    return -1;
                }
                isFlipped[i] = 1;
                flipped ^= 1;
                result++;
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> A = {0,0,0,1,0,1,1,0};
    s.minKBitFlips(A, 3);
}
