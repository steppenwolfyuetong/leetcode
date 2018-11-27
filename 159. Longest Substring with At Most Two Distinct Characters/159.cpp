/*
 * Given a string, find the length of the longest substring T that contains at most 2 distinct characters.
 * For example,Given s = "eceba",
 * T is "ece" which its length is 3.
 */

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if(s.empty())
            return 0;

        vector<int> table(128, 0);
        int start = 0, end = 0;
        int count = 0, len = 0;
        while(end < s.size())
        {
            if(table[s[end++]]++ == 0)
            {
                count++;
            }

            while(count > 2)
            {
                if(table[s[start++]]-- == 1)
                {
                    count--;
                }
            }
            len = max(len, end - start);
        }
        return len;
    }
};

int main()
{
    Solution *sol = new Solution();
    string s = "eceba";
    cout << sol->lengthOfLongestSubstringTwoDistinct(s) << endl;
}
