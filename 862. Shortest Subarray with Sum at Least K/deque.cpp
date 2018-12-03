/*
 *  https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/discuss/189039/Detailed-intuition-behind-Deque-solution
 *
 *
    Calculate prefix sum B of list A.
    B[j] - B[i] represents the sum of subarray A[i] ~ A[j-1]
    Deque d will keep indexes of increasing B[i].
    For every B[i], we will compare B[i] - B[d[0]] with K.

    Time Complexity:
    Loop on B O(N)
    Every index will be pushed only once into deque. O(N)
*/

int shortestSubarray(vector<int> A, int K) {
    int N = A.size(), res = N + 1;

    vector<int> B(N + 1, 0);
    for (int i = 0; i < N; i++) 
        B[i + 1] = B[i] + A[i];

    deque<int> d;

    /*
     * So that when we move the start pointer and we violate the condition, we are sure we will violate it if we keep taking the other values from the Deque. 
     * In other words, if the sum of the subarray from start=first value in the deque to end is smaller than target, then the sum of the subarray from start=second value in the deque to end is necessarily smaller than target.
     * So because the Deque is increasing (B[d[0]] <= B[d[1]]), we have B[i] - B[d[0]] >= B[i] - B[d[1]], which means the sum of the subarray starting from d[0] is greater than the sum of the sub array starting from d[1].
     */
    for (int i = 0; i < N + 1; i++) {
        while (d.size() > 0 && B[i] - B[d.front()] >= K) {
            res = min(res, i - d.front())
            d.pop_front();
        }

        while (d.size() > 0 && B[i] <= B[d.back()]) {
            d.pop_back();
        }
        d.push_back(i);
    }

    return res <= N ? res : -1;
}
