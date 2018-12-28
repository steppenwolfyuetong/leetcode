/*
We need to split the array into left '0' and right '1' sub-arrays, 
so that sum of '1' -> '0' flips (left) and '0' -> '1' flips (right) is minimal.

Count of '1' -> '0' flips going left to right, and store it in left.
Count of '0' -> '1' flips going right to left, and store it in right.
Find a the smallest f0[i] + f1[i].
*/

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string S) {
        vector<int> left(S.size(), 0), right(S.size(), 0);

        // count all 1 on the left of i, i not included
        for (int i = 1; i < S.size(); i++) {
            left[i] = left[i-1] + S[i-1] - '0';
        }
        // count all 0 ont the right of i, i not included
        for (int i = S.size() - 2; i >= 0; i--) {
            right[i] = right[i+1] + '1' - S[i+1];
        }

        int result = S.size();
        for (int i = 0; i < S.size(); i++) {
            // (all 1 on the left of i) + (all 0 on the right of i), S[i] itself doesn't matter
            result = min(result, left[i] + right[i]);
        }
        return result;
    }
};

int main() {
    Solution *s = new Solution();
    cout << s->minFlipsMonoIncr("010110") << endl;
    cout << s->minFlipsMonoIncr("000100") << endl;
    return 0;
}
