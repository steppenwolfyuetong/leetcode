/*
    For base b (decimal case b = 10), the digit root of an integer is:

    dr(n) = 0 if n == 0
    dr(n) = (b-1) if n != 0 and n % (b-1) == 0
    dr(n) = n mod (b-1) if n % (b-1) != 0

    or

    dr(n) = 1 + (n - 1) % 9

    Note here, when n = 0, since (n - 1) % 9 = -1, the return value is zero (correct).
*/

class Solution {
public:
    int addDigits(int num) {
        return 1 + (num - 1) % 9
    }
};
