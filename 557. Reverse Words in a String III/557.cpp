class Solution {
public:
    string reverseWords(string s) {
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != ' ')
            {
                int j = i;
                while(j < s.size() && s[j] != ' ')
                    j++;
                reverse(s.begin() + i, s.begin() + j);
                i = j - 1;
            }
        }
        return s;
    }
};


/*
 * python:

 class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        words = s.split(' ')
        return ' '.join(word[::-1] for word in words)
 */
