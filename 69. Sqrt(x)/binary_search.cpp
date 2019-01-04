// find a number target which is minimum and satisfy 
//  1. (taget) * (target) <= x
//  2. (taget + 1) * (target + 1) > x

class Solution {
public:
    int mySqrt(int x) {
        // loop invariant: low <= target <= high
        long low = 0, high = x;

        // when low + 1 = high, it will not loop forever, so low < high is ok, and low is the target
        while (low < high) {
            long mid = low + (high - low) / 2;
            if (mid * mid <= x && (mid + 1) * (mid + 1) > x) {
                return mid;
            } else if (mid * mid <= x) {
                low = mid + 1;          // mid can't be target, because (mid + 1) * (mid + 1) <= x
            } else {
                high = mid - 1;         // mid can't be target, mid * mid > x
            }
        }
        return low;
    }
};

/*
// find a number target which is minimum and target * target > x
// so the ans is target - 1
// bu this can not handle overflow of x = INT_MAX

class Solution {
public:
    int mySqrt(int x) {
        // loop invariant: low <= target <= high
        long low = 0, high = x + 1;              // if x = 1, target is 2, wo high = x + 1

        // when low + 1 = high, it will not loop forever, so low < high is ok, and low is the target
        while (low < high) {
            long mid = low + (high - low) / 2;
            if (mid * mid <= x) {
                low = mid + 1;          // mid can't be target
            } else {
                high = mid;             // mid can be target
            }
        }
        return low - 1;
    }
};
*/
