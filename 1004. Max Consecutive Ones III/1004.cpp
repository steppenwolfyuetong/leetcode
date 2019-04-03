class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int start = 0, end = 0;
        int len = 0, count = 0;         // count is the times we change 0 to 1

        while (end < A.size()) {
            if (A[end++] == 0) {
                count++;
            }
            while (count > K) {
                if (A[start++] == 0) {
                    count--;
                }
            }
            if (end - start > len) {
                len = end - start;
            }
        }
        return len;
    }
};
