/*
How many magic numbers <= x ?
By inclusion exclusion principle, we have:
x / A + x / B - x / lcm

low = min(A, B)
high = N * min(A, B)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int nthMagicalNumber(int N, int A, int B) {
        long lcm = A * B / __gcd(A, B);
        int mod = 1e9 + 7;

        // loop invarient: with target is Nth magical number, low <= target <= high
        // need to cast to long in case of overflow
        long low = min(A, B), high = (long)N * min(A, B);
        while (low < high) {
            long mid = low + (high - low) / 2;
            if (mid / A + mid / B - mid / lcm >= N) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low % mod;
    }
};

int main() {
    Solution *s = new Solution();
    cout << s->nthMagicalNumber(1000000000, 40000, 40000) << endl;
    return 0;
}
