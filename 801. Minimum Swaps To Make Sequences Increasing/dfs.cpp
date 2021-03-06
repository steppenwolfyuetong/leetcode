// Author: Huahua
// Running time: TLE 84/102 test cases passed.
class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int ans = INT_MAX;
        dfs(A, B, 0, 0, ans);
        return ans;
    }
private:
    void dfs(vector<int>& A, vector<int>& B, int i, int c, int& ans) {
        if (c >= ans) {
            return;
        }

        if (i == A.size()) {
            ans = min(ans, c);
            return;
        }

        if (i == 0 || A[i] > A[i - 1] && B[i] > B[i - 1]) {
            dfs(A, B, i + 1, c, ans);
        }

        if (i == 0 || A[i] > B[i - 1] && B[i] > A[i - 1]) {
            swap(A[i], B[i]);
            dfs(A, B, i + 1, c + 1, ans);
            swap(A[i], B[i]);
        }
    }
};
