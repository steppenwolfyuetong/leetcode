/*
 * 1. in the first pass I record counts of every character in a hashmap
 * 2. in the second pass I locate the first character that appear less than k times in the string.
 *    this character is definitely not included in the result, and that separates the string into two parts.
 * 3. keep doing this recursively and the maximum of the left/right part is the answer.
 */

#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        if(k == 0)
            return s.size();
        if(s.empty() || k > s.size())
            return 0;

        unordered_map<int, int> table;
        for(auto ch : s)
            table[ch]++;

        int index = 0;
        while(index < s.size() && table[s[index]] >= k)
        {
            index++;
        }
        if(index == s.size())
            return s.size();

        int left = longestSubstring(s.substr(0, index), k);
        int right = longestSubstring(s.substr(index + 1), k);
        return max(left, right);
    }
};

int main()
{
    Solution *sol = new Solution();
    string s = "ababbc";
    int k = 2;
    cout << sol->longestSubstring(s, k) << endl;
}
