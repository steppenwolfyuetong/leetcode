// http://zxi.mytechroad.com/blog/dynamic-programming/leetcode-801-minimum-swaps-to-make-sequences-increasing/
/*
 *  swap[i] min swap with swapping A[i] and B[i]
 *  keep[i] min swap without swapping A[i] and B[i]
 *
 *  There four case:
 *  1. swap at index i - 1 and i
 *  2. don't swap at index i - 1 and i
 *  3. swap at index i - 1
 *  3. swap at index i
 *
 *
 *  It is guaranteed that the given input always makes it possible.
 *  1. A[i-1] < A[i] && B[i-1] < B[i]
 *
 *  2. A[i-1] < B[i] && B[i-1] < A[i]
 *
 */

class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> swap(n, INT_MAX);
        vector<int> keep(n, INT_MAX);
        keep[0] = 0;
        swap[0] = 1;

        for (int i = 1; i < n; i++) {
            if (A[i-1] < A[i] && B[i-1] < B[i]) {
                keep[i] = min(keep[i], keep[i-1]);              // neither swap at index i-1 and i
                swap[i] = min(swap[i], swap[i-1] + 1);          // both swap at index i-1 and i
            }
            if (A[i-1] < B[i] && B[i-1] < A[i]) {
                // If A[i-1] and B[i-1] are swapped, we don't need to swap A[i] and B[i].
                // Otherwise, we need to swap A[i] and B[i].
                keep[i] = min(keep[i], swap[i - 1]);            // swap at index i - 1
                swap[i] = min(swap[i], keep[i - 1] + 1);        // swap at index i
            }
        }
        return min(swap[n-1], keep[n-1]);
    }
};
