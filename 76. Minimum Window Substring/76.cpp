#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        string rt;
        if(s.empty() || t.empty())
            return rt;

        vector<int> table(128, 0);
        for(auto ch : t)
        {
            table[ch]++;
        }

        int count = t.size();
        int start = 0, end = 0, len = INT_MAX;
        while(end < s.size())
        {
            // 每次将end向右移
            if(table[s[end++]]-- >= 1)
            {
                count--;
            }

            // s.substr(start, end - start)满足条件
            while(count == 0)
            {
                // 更新结果
                if(end - start < len)
                {
                    rt = s.substr(start, end - start);
                    len = end - start;
                }
                // start向右移 缩小窗
                // 直至table[s[start]]为0，如果窗不包含start，则子字符串中不包含所有t中的字符
                if(table[s[start++]]++ == 0)
                {
                    count++;
                }
            }
        }
        return rt;
    }
};

int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    Solution *sol = new Solution();
    cout << sol->minWindow(s, t) << endl;
}
