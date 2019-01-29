// see leetcode 214
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        vector<int> next = buildPrefixTable(needle);        
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (haystack[i] == needle[j]) {
                i++, j++;
            } else if (j > 0) {
                j = next[j - 1];
            } else {
                i++;
            }
        }

        if (j == needle.size()) {
            return i - j;
        } else {
            return -1;
        }
    }

    vector<int> buildPrefixTable(const string& pat) {
        vector<int> next(pat.size(), 0);
        int i = 1, j = 0;
        while (i < pat.size()) {
            if (pat[i] == pat[j]) {
                next[i] = j + 1;
                i++, j++;
            } else if (j > 0) {
                j = next[j - 1];
            } else {
                i++;                 
            }
        }
        return next;
    }
};

