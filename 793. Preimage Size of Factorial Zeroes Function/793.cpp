#include <iostream>
using namespace std;

// Let f(x) be the number of zeroes at the end of x!. (Recall that x! = 1 * 2 * 3 * ... * x, and by convention, 0! = 1.)
//
// 1. f(x) is non-decreasing, and f(x) is the count of factor 5 in x!
// 2. preimageSizeFZF is count of f(x) = K
//
// https://leetcode.com/problems/preimage-size-of-factorial-zeroes-function/discuss/117821/Four-binary-search-solutions-based-on-different-ideas

class Solution {
public:
    int preimageSizeFZF(int K) {
        if (K == 0) {               // binary(0) - binary(-1) = 4 
            return 5;
        }
        return binary(K) - binary(K - 1);
    }

    // return max of x which satisfy f(x) <= K, 
    //
    // ps: there is some K which satisfy premageSizeFZF(K) = 0
    //
    // x! will always have at least x/5 trailing zeros, therefore, 
    // if x is the largest integer such that x! has no more than K trailing zeros, then we have x < 5 * (K + 1)
    int binary(long K) {                        
        // invariant: result in range [start, end)
        long start = 0, end = 5 * (K + 1);      // K <= 10^9, 5*K > INT_MAX, so use long

        while (start + 1 < end) {               // when start + 1 == end, may fail in loop, so we need to handle it
            long mid = start + (end - start) / 2;
            int zeros = trailingZeros(mid);
            if (zeros <= K) {                   // mid itself can the result, as for when trailingZeros(mid) < K
                start = mid;                    // trailingZeros(mid + 1) could > K, so mid may be the result as well.
            } else if (zeros > K) {             // mid itself can't be the result
                end = mid - 1;
            }
        }

        if (trailingZeros(end) <= K) {
            return end;
        } else {
            return start;
        }
    }

    // count factor of 5 by finding the multiples of 5, 25, 125, ...
    int trailingZeros(long num) {
        int result = 0;
        while (num > 0) {
            result += num / 5;
            num /= 5;
        }
        return result;
    }
};

int main() {
    Solution s;
    cout << s.preimageSizeFZF(99999) << endl;
}
