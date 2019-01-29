/*
We can construct the following string and run KMP algorithm on it:
(s) + (some symbol not present in s) + (reversed string)

After running KMP on that string as result we get a vector `next` with values of a prefix function for each character (for definition of a prefix function see KMP algorithm description). We are only interested in the last value because it shows us the largest suffix of the reversed string that matches the prefix of the original string. 
So basically all we left to do is to add the first k characters of the reversed string to the original string, where k is a difference between original string size and the prefix function for the last character of a constructed string.

KMP Explainatation: https://www.youtube.com/watch?v=GTJr8OvyEVQ
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string pat = s + "#" + rev;
        
        vector<int> next = buildPrefixTable(pat);
        
        return rev.substr(0, s.size() - next[pat.size() - 1]) + s;
    }

    // build kmp next vector
    vector<int> buildPrefixTable(string pat) {
        vector<int> next(pat.size(), 0);
        for (int i = 1; i < pat.size(); i++) {
            int j = next[i - 1];
            while (j > 0 && pat[i] != pat[j])
                j = next[j - 1];
            next[i] = (j += pat[i] == pat[j]);
        }
        return next;
    }
};

int main() {
    Solution s;
    cout << s.shortestPalindrome("aabaaa") << endl;;
    return 0;
}
