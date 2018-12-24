class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if (A.size() <= 1) {
            return true;
        }
        bool inc = false, dec = false;
        for (int i = 1; i < A.size(); i++) {
            if (A[i] > A[i-1]) {
                inc = true;
            } else if (A[i] < A[i-1]) {
                dec = true;
            }

            if (inc && dec) {
                return false;
            }
        }
        return true;
    }
};
