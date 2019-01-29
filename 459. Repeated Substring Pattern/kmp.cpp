/*
My p[i] stands for longest common string length of prefix string and the string ended with position i.

The important point is the last one: len % (len - p[len - 1]) == 0

for a string like below, if p[len-1] = 15, len=20:
#####~~~~~^^^^^$$$$$

by p[len-1] = 15, we know the prefix is #####~~~~~^^^^^ and suffix is ~~~~~^^^^^$$$$$, prefix = suffix.

so you can infer that:
##### == ~~~~~
~~~~~ == ^^^^^
^^^^^ == $$$$$

The whole is repeating as #####
the length of it is 5, which can be completely divided by len.

*/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        vector<int> next(s.size(), 0);
        int n = s.size();
        int i = 1, j = 0;
        while (i < n) {
            if (s[i] == s[j]) {
                dp[i] = j + 1;
                i++, j++;
            } else if (j > 0) {
                j = next[j - 1];
            } else {
                i++;
            }
        }

        // !!!
        return next.back() && n % (n - next.back()) == 0;
    }
};
