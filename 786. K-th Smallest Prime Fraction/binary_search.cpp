class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        double low = 0, high = 1;
        int p = 0, q = 0;
        int n = A.size();
        int count = 0;              // count of element <= mid

        while (count != K) {
            count = 0;
            double mid = (low + high) / 2.0, upper = 0.0;

            // count fraction A[i]/A[j] <= mid, i < j, A[i]/A[j] is monotonically decreasing as j increases
            // use `upper` store the upper_bound(mid)
            for(int i = 0, j = i + 1; i < n; i++) {
                // skip fraction > mid
                while(j < n && A[i] > mid * A[j])
                    j++;
                
                if (j == n || (count += n - j) > K)
                    break;

                if (A[i] > upper * A[j]) {
                    upper = A[i] / (double) A[j] ;
                    p = A[i];
                    q = A[j];
                }
            }

            if (count > K) {
                high = mid;
            } else {
                low = mid;
            }
        }
        return vector<int>{p, q};
    }
};
