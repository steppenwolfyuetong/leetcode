class Solution {
public:
    // same as 378. Kth Smallest Element in a Sorted Matrix
    int findKthNumber(int m, int n, int k) {
        // invarient: with target is kth smallest element, low <= target <= high, 
        int low = 1, high = m * n;

        while (low < high) {
            int mid = (low + high) / 2;
            
            // count elements <= mid
            int count = 0;
            for (int i = 1; i <= m; i++) {
                count += min(mid / i, n);
            }

            // k is the target
            // count of [low, mid] < k, so the target's range must in (mid, high]
            // count of [low, mid] >= k, so the target's range must in [low, mid]
            //
            // and we need to handle the case when low + 1 = high
            // it won't loop forever, so while (left < right)
            if (count < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }
};

