// Substring template

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, end = 0;
        int count = 0, len = 0;
        vector<int> table(256, 0);

        while(end < s.size())
        {
            // 子串中已经有s[end], count++
            // end往右移动
            if(table[s[end++]]++ > 0)
            {
                count++;
            }

            while(count > 0)
            {
                // start往右移动
                // 使子串中s[start]只有一个
                if(--table[s[start++]] == 1)
                {
                    count--;
                }
            }
            len = max(len, end - start);
        }
        return len;
    }
};
