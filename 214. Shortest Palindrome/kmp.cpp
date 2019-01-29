#include <string>
#include <vector>
#include <iostream>
using namespace std;

// for kmp algorithm, see kmp-1.cpp

class Solution {
public:
    int kmp(string text, string pat) {
        vector<int> next = buildPrefixTable(pat);
        int i = 0, j = 0;
        while (i < text.size() && j < (int) pat.size()) {
            if (j == -1 || text[i] == pat[j]) {
                i++;
                j++;
            } else {
                j = next[j];            // if we shift the next, we can ignore the case when j - 1 < 0 int kmp-1.cpp
            }
        }

        if (j == pat.size()) {
            return i - j;
        } else {
            return -1;
        }
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

        // shift the next vector to the right, and insert -1 to the beginning.
        next.pop_back();
        next.insert(next.begin(), -1);
        return next;
    }
};

int main() {
    Solution s;
    cout << s.kmp("abxabcabcaby", 
                  "abcaby") 
         << endl;

    cout << s.kmp("abxabcabcaby", 
                  "y") 
         << endl;
    return 0;
}
