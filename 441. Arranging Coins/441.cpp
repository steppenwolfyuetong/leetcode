#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
    // O(1)
    // 1 + 2 + ... + x <= n
    // x * (x + 1) / 2 <= n
    int arrangeCoins(int n) {
        return (int)(0.5 * (-1 + sqrt(1 + 8 * (long)n)));
    }

    // O(logn)
    // binary search
    int arrangeCoins1(int n) {
        long low = 1, high = n;
        while(low <= high)
        {
            int mid = low + ((high - low) >> 1);
            if(0.5 * mid * (mid + 1) <= n)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low - 1;
    }
};

int main()
{
    Solution *s = new Solution();
    int n;

    n = 5;
    cout << s->arrangeCoins(n) << endl;
    cout << s->arrangeCoins1(n) << endl;
    n = 16;
    cout << s->arrangeCoins(n) << endl;
    cout << s->arrangeCoins1(n) << endl;
}
