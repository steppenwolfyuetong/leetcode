/*
    Sliding window, similar to finding longest substring with k distinct characters

    The problem says that we can make at most k changes to the string (any character can be replaced with any other character).
    So, let's say there were no constraints like the k. Given a string convert it to a string with all same characters with minimal changes.
    The answer to this is
        length of the entire string - number of times of the maximum occurring character in the string

    Given this, we can apply the at most k changes constraint and maintain a sliding window such that
        (length of substring - number of times of the maximum occurring character in the substring) <= k
 */


#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int start = 0, end = 0;
        int maxCount = 0, len = 0;             // maxCount保存[start,end]区间内最大重复字母个数
        vector<int> table(128, 0);
        while(end < s.size())
        {
            // update maxCount
            maxCount = max(maxCount, ++table[s[end++]]);

            // 条件不满足时移动窗
            while(end - start - maxCount > k)
            {
                table[s[start++]]--;
            }
            len = max(len, end - start);
        }
        return len;
    }
};

int main()
{
    Solution *s = new Solution();
    cout << s->characterReplacement("AABABBA", 1) << endl;
    return 0;
}
