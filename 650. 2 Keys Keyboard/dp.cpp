/*
 * for example:
 * with last copy of 2, the result must be 2n, {need to copy n, and paste (2-1) times}, and goes for n
 * with last copy of 3, the result must be 3n, {need to copy n, and paste (3-1) times}, and goes for n
 * with last copy of 5, the result must be 5n, {need to copy n, and paste (5-1) times}, and goes for n
 *                                                      which is 2,3,5 in total
 *
 * as for prime number n, the answer is n
 * as for composite number, the answer depends on the factor
 *
 * basiclly is to Factorization
 */



class Solution {
public:
    int minSteps(int n) {
        int s = 0;
        for (int d = 2; d <= n; d++) {
            while (n % d == 0) {
                s += d;
                n /= d;
            }
        }
        return s;
    }
};

// dp
public int minSteps(int n) {
    int[] dp = new int[n+1];

    for (int i = 2; i <= n; i++) {
        dp[i] = i;
        for (int j = i / 2; j > 1; j--) {
            if (i % j == 0) {
                dp[i] = dp[j] + (i/j);
                break;
            }
        }
    }
    return dp[n];
}
