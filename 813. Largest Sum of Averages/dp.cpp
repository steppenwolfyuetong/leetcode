/*
We partition a row of numbers A into at most K adjacent (non-empty) groups, then our score is the sum of the average of each group. 
What is the largest score we can achieve?
Note that our partition must use every number in A, and that scores are not necessarily integers.

A = [9,1,2,3,9]
K = 3
Output: 20
Explanation:
The best choice is to partition A into [9], [1, 2, 3], [9]. The answer is 9 + (1 + 2 + 3) / 3 + 9 = 20.
*/

/*
 *  dp[i][j]: sum of averages of A[0,i) and j groups, invariant
 *  
 *  init state:
 *      dp[i][0] = 0
 *      dp[0][j] = 0
 *      dp[i][1] = avg(A[0,i))
 *
 *  dp[i][j] = max(dp[i-1][j-1] + A[i-1],                                       // A[i-1] is a new group
 *                 dp[i - n][j - 1] + (A[i - n] + ... + A[i-1]) / n)            // A[i-1] belongs to last group, group size is n
 *
 *  i - n >= j - 1, A[0, i - n) has j - 1 group, and A[i - n, i - 1) forms the j-th group
 *  其实dp[i-1][j-1] + A[i-1]即为n = 1的情形
 *
 *  ans: max(A[i][...])
 */
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        if (K <= 0 || A.empty()) {
            return 0;
        }

        vector<vector<double>> dp(A.size() + 1, vector<double>(K + 1, 0));
        double sum = 0;
        for (int i = 1; i <= A.size(); i++) {
            sum += A[i - 1];
            dp[i][1] = sum / i;
        }

        for (int j = 2; j <= K; j++) {                          // group count
            for (int i = 1; i <= A.size(); i++) {
                // n is last group size
                double sum = 0;
                for (int n = 1; i - n >= j - 1; n++) {          // A[0,i - n) has j - 1 group, and last n elements is j-th group
                    sum += A[i - n];
                    dp[i][j] = max(dp[i][j], dp[i - n][j - 1] + (sum / n));
                }
            }
        }

        double result = 0;
        for (int j = 1; j <= K; j++) {
            result = max(result, dp[A.size()][j]);
        }
        return result;
    }

    void display(vector<vector<double>> &dp) {
        for(int i = 0; i < dp.size(); i++) {
            for(int j = 0; j < dp.front().size(); j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main() {
    Solution *s = new Solution();
    vector<int> A{9,1,2,3,9};
    cout << s->largestSumOfAverages(A, 3) << endl;
    A = {1,2,3,4,5,6,7};
    cout << s->largestSumOfAverages(A, 4) << endl;
    return 0;
}
