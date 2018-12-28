/*
 *  swap[i] min swap with swapping A[i] and B[i]
 *  unswap[i] min swap without swapping A[i] and B[i]
 *
 *  It is guaranteed that the given input always makes it possible.
 *  1. A[i-1] < A[i] && B[i-1] < B[i]
 *
 *
 *  2. A[i-1] < B[i] && B[i-1] < A[i]
 *
 */

class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> swap(n, INT_MAX);
        vector<int> unswap(n, INT_MAX);
        unswap[0] = 0;
        swap[0] = 1;

        for (int i = 1; i < n; i++) {
            if (A[i-1] < A[i] && B[i-1] < B[i]) {
                unswap[i] = min(unswap[i], unswap[i-1]);        // neither swap at index i-1 and i
                swap[i] = min(swap[i], swap[i-1] + 1);          // both swap at index i-1 and i
            }
            if (A[i-1] < B[i] && B[i-1] < A[i]) {
                // If A[i-1] and B[i-1] are swapped, we don't need to swap A[i] and B[i].
                // Otherwise, we need to swap A[i] and B[i].
                unswap[i] = min(unswap[i], swap[i - 1]);
                swap[i] = min(swap[i], unswap[i - 1] + 1);
            }
        }
        return min(swap[n-1], unswap[n-1]);
    }
};
