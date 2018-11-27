#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> rt;
        if(s.empty() || p.empty())
            return rt;

        vector<int> table(256, 0);
        for(auto ch : p)
        {
            table[ch]++;
        }

        int count = p.size();
        int start = 0, end = 0;
        while(end < s.size())
        {
            if(table[s[end++]]-- > 0)
            {
                count--;
            }

            while(count == 0)
            {
                if(end - start == p.size())
                {
                    rt.push_back(start);
                }

                if(table[s[start++]]++ >= 0)
                {
                    count++;
                }
            }
        }
        return rt;
    }
};
