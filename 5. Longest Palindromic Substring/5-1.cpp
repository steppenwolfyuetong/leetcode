#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = 0;
        int startIndex = 0;
        for(int i = 0; i < s.size(); i++)
        {
            int index = i;
            int len1 = getLongestPalindromeLength(s, i, i, index);
            if(len1 > len)
            {
                len = len1;
                startIndex = index;
            }

            index = i;
            int len2 = getLongestPalindromeLength(s, i, i + 1, index);
            if(len2 > len)
            {
                len = len2;
                startIndex = index;
            }
        }
        return s.substr(startIndex, len);
    }

    int getLongestPalindromeLength(string s, int left, int right, int &index)
    {
        while(left >= 0 && right < s.size() && s[left] == s[right])
        {
            index = left;
            left--;
            right++;
        }
        cout << index << ' ' << right - left - 1 << endl;
        return right - left - 1;
    }
};

int main()
{
    Solution *s = new Solution();
    cout << s->longestPalindrome("") << endl;
    return 0;
}
