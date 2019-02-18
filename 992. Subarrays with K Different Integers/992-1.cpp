// https://leetcode.com/problems/subarrays-with-k-different-integers/discuss/235235/C%2B%2B-with-picture-7-lines-56-ms
// 159 340

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        vector<int> dict(A.size() + 1, 0);          // count of each numbers in sliding window
        int start = 0, end = 0; 
        int count = 0, result = 0;                  // count is the count of distinct numbers
        int prefix = 0;                             // prefix is the parts can be shrinked from the k distinct sliding window
        while (end < A.size()) {
            if (dict[A[end++]]++ == 0) {
                count++;
            }
            if (count > K) {
                --dict[A[start++]];
                prefix = 0;
                count--;
            }
            while (dict[A[start]] > 1) {            // move start to the position so that A[i] only appear once
                prefix++; 
                dict[A[start++]]--;
            }

            if (count == K) {
                result += prefix + 1;
            }
        }
        return result;
    }
};

// If the subarray [i, j] contains K unique numbers, and first prefix numbers also appear in [i + prefix, j] subarray, 
// we have total 1 + prefix good subarrays. 
//
// For example, there are 3 unique numers in [1, 2, 1, 2, 3]. 
// First two numbers also appear in the remaining subarray [1, 2, 3], 
// so we have 1 + 2 good subarrays: [1, 2, 1, 2, 3], [2, 1, 2, 3] and [1, 2, 3].

// We can iterate through the array and use two pointers for our sliding window ([i, j]). 
// The back of the window is always the current position in the array (j). 
// The front of the window (i) is moved so that A[i] appear only once in the sliding window. 
// In other words, we are trying to shrink our sliding window while maintaining the same number of unique elements.


