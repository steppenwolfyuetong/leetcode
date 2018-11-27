#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // same as 438
        if(s1.empty())
            return s2.empty();

        vector<int> table(256, 0);
        for(auto ch : s1)
        {
            table[ch]++;
        }

        int count = s1.size();
        int start = 0, end = 0;
        while(end < s2.size())
        {
            if(table[s2[end++]]-- > 0)
            {
                count--;
            }

            while(count == 0)
            {
                if(end - start == s1.size())
                {
                    return true;
                }

                if(table[s2[start++]]++ >= 0)
                {
                    count++;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution *s = new Solution();
    cout << s->checkInclusion("ab", "eidbaooo") << endl;
    cout << s->checkInclusion("ab", "eidboaooo") << endl;
    cout << s->checkInclusion("adc", "dcda") << endl;
}
