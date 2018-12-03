// search index that A[i-1] < A[i] and A[i] > A[i+1]

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        // There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
        // invarient: low < target < high 
        int low = 0, int high = A.size() - 1;

        while (high - low > 2) {
            int i = (low + high) / 2;
            if (A[i - 1] < A[i] && A[i] < A[i + 1]) {
                // A[i] can't be the target, so set low = i < target < high
                low = i;
            } else if (A[i - 1] > A[i] && A[i] > A[i + 1]) {
                // A[i] can't be the target, so set low < target < high = i
                high = i;
            } else {
                return i;
            }
        }
        return (low + 1);
    }
};
