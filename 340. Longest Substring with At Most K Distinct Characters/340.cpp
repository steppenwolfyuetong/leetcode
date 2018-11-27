// refer to 159 and others/substring

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(s.empty() || k <= 0)
            return 0;

        int start = 0, end = 0;
        int count = 0, len = 0;
        vector<int> table(128, 0);
        while(end < s.size())
        {
            if(table[s[end++]]++ == 0)
            {
                count++;
            }

            while(count > k)
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
    int k = 3;
    cout << sol->lengthOfLongestSubstringKDistinct(s, k) << endl;
}
