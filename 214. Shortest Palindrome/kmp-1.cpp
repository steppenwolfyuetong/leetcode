#include <string>
#include <vector>
#include <iostream>
#include <assert.h>
using namespace std;

// https://blog.csdn.net/v_july_v/article/details/7041827
// KMP Explainatation: https://www.youtube.com/watch?v=GTJr8OvyEVQ
//                     https://www.bilibili.com/video/av3246487/

class Solution {
public:
    int kmp(string text, string pat) {
        vector<int> next = buildPrefixTable(pat);
        int i = 0, j = 0;
        while (i < text.size() && j < (int) pat.size()) {
            if (text[i] == pat[j]) {
                i++;
                j++;
            } else {
                // set the j to the prefix/suffix length of previous character. 
                // (失配时，模式串向右移动的位数为：已匹配字符数 - 失配字符的上一位字符所对应的最大长度值)
                if (j > 0) {                    
                    j = next[j - 1];
                } else {                    // the first character doesn't match
                    i++;
                    j = 0;
                }
            }
        }

        if (j == pat.size()) {
            return i - j;
        } else {
            return -1;
        }
    }

    // build kmp next vector,
    // 
    //      0 1 2 3 4 5 6 7 8
    // pat: a a b a a b a a a
    // next:0 1 0 1 2 3 4 5 2
    //
    // next[i]: the length of prefix and suffix are the same. (当前字符之前的字符串中，有多大长度的相同前缀后缀)
    // next[0] = 0 (there must be different index between prefix and suffix)
    //
    // for aaba, prefix = suffix = a (first a and last a are the prefix and suffix), so next[3] = 1
    // for aabaab, prefix = suffix = aab, so next[5] = 3
    // for aabaabaa, prefix = suffix = aabaa, so next[7] = 5
    //
    // text:aabaabcccccc
    // pat: aabaabaa
    //
    // so text and pat fails at index 6, so we check the next[5], which is 3,
    // it means there is a prefix/suffix of length 3 has already been matched (aab), 
    // so we can directly check pattern starting from the 4th chracter.
    vector<int> buildPrefixTable(string pat) {
        vector<int> next(pat.size(), 0);
        for (int i = 1; i < pat.size(); i++) {
            // if we know next[0, i-1], we can get next[i] as follows:
            //
            // according to the definition of next vector, when we want to calculate next[i],
            // next[i-1] has the length of same prefix/suffix length of j, we can check whether pat[i] and pat[j] are equal.
            //
            // 1. if equal, next[i] = j + 1 (extends next[i - 1]'s prefix/suffix)
            // 2. if not equal, we can't have same prefix/suffix of length j + 1, so we have to look for shorter same prefix/suffix,
            //    that is, let j' = next[j - 1]. ( pat[0,j') is the prefix, pat[j - j', j) is the suffix )
            //    next[j-1] has the length of same prefix/suffix length of j', we can check whether pat[i] and pat[j'] are equal.
            int j = next[i - 1];

            while (j > 0 && pat[i] != pat[j]) {
                j = next[j - 1];                // recursively try to find shorter same prefix/suffix
            }
            next[i] = (j += pat[i] == pat[j]);
        }
        return next;
    }

    // essentially the same as previous one
    vector<int> buildPrefixTable2(string pat) {
        vector<int> next(pat.size(), 0);
        int i = 1, j = 0;
        while (i < pat.size()) {
            if (pat[i] == pat[j]) {
                next[i] = j + 1;
                i++, j++;
            } else {
                if (j > 0) {
                    j = next[j - 1];
                } else {
                    next[i++] = 0;
                }
            }
        }
        return next;
    }
};

int main() {
    Solution s;
    cout << s.kmp("abxabcabcaby", 
                  "abcaby") 
         << endl;


    vector<int> next = s.buildPrefixTable("aabaabaaa");
    vector<int> next2 = s.buildPrefixTable2("aabaabaaa");
    assert(next == next2);

    next = s.buildPrefixTable("abcdabca");
    next2 = s.buildPrefixTable2("abcdabca");
    assert(next == next2);

    next = s.buildPrefixTable("abaaba");
    next2 = s.buildPrefixTable2("abaaba");
    assert(next == next2);

    return 0;
}
