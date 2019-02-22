// https://leetcode.com/problems/broken-calculator/discuss/234484/JavaC%2B%2BPython-Change-Y-to-X-in-1-Line

/*
Intuition:
    Considering how to change Y to X
    Opertation 1: Y = Y / 2 if Y is even
    Opertation 2: Y = Y + 1


Explanation:
* Obviously, If Y <= X, we won't do Y / 2 anymore. We will increase Y until it equals to X

* So before that, while Y > X, we'll keep reducing Y, until it's smaller than X.
    If Y is odd, we can do only Y = Y + 1
    If Y is even, if we plus 1 to Y, then Y is odd, we need to plus another 1.
    And because (Y + 1 + 1) / 2 = (Y / 2) + 1, 3 operations are more than 2.
    We always choose Y / 2 if Y is even.

Why it's right:
    Actually, what we do is:
    If Y is even, Y = Y / 2
    If Y is odd, Y = (Y + 1) / 2

We reduce Y with least possible operations, until it's smaller than X.

And we know that, we won't do Y + 1 twice in a row.
Becasue we will always end with an operation Y / 2.

2N times Y + 1 and once Y / 2 needs 2N + 1 operations.
Once Y / 2 first and N times Y + 1 will end up with same result, but needs only N + 1 operations.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int brokenCalc(int X, int Y) {
        int res = 0;
        while (Y > X) {
            Y = Y % 2 ? Y + 1 : Y / 2;
            res++;
        }
        return res + X - Y;
    }
};

int main() {
    Solution s;
    cout << s.brokenCalc(2, 3) << endl;
    //cout << s.brokenCalc(5, 8) << endl;
    //cout << s.brokenCalc(3, 10) << endl;
    //cout << s.brokenCalc(1024, 1) << endl;
}
