#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

// https://leetcode.com/problems/subarrays-with-k-different-integers/discuss/234482/JavaC%2B%2BPython-Sliding-Window-with-Video
// 159 340

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        // count(K distinct) = count(at most k distinct) - count(at most k - 1 distinct)
        return withAtMostKDistinct(A, K) - withAtMostKDistinct(A, K - 1);
    }

    int withAtMostKDistinct(vector<int> &A, int K) {
        int start = 0, end = 0;
        int result = 0;
        vector<int> dict(A.size() + 1, 0);          // count of each numbers in sliding window

        // move the end each time, and try to find the subarray meet requirement
        while (end < A.size()) {
            if (dict[A[end++]]++ == 0) {
                K--;
            }

            // only keep a sliding window of at most k distinct number
            while (K < 0) {
                if (--dict[A[start++]] == 0) {
                    K++;
                }
            }

            // when come to this, we have a sliding window of [start, end) and has at most k distinct numbers
            // for example, start = 0, end = 4, sliding window is {1, 2, 1, 2} 
            // so the subarray ending with index 3 is {1212},{212},{12},2}
            // result need to add length of sliding window
            result += end - start;
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> A = {1,2,1,2,3};
    cout << s.subarraysWithKDistinct(A, 2) << endl;
}
