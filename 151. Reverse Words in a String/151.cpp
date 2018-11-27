#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
*/


class Solution
{
public:
    // stack
    void reverseWords(string &s)
    {
        stack<char> word;
        stack<char> sentence;

        for(int i = 0; i <= s.size(); i++)
        {
            if(i == s.size() || s[i] == ' ')
            {
                if(!word.empty())
                {
                    if(!sentence.empty())
                    {
                        sentence.push(' ');
                    }
                }
				while(!word.empty())
				{
					sentence.push(word.top());
					word.pop();
				}
            }
            else
            {
                word.push(s[i]);
            }
        }
        s.clear();
        while(!sentence.empty())
        {
            s.push_back(sentence.top());
            sentence.pop();
        }
    }

    // O(1)
    void reverseWords1(string &s)
    {
        reverse(s.begin(), s.end());
        int index = 0, cur = 0;
        while(cur < s.size())
        {
            while(cur < s.size() && s[cur] == ' ')
            {
                cur++;
            }
            if(index != 0)
            {
                s[index++] = ' ';
            }
            int i = cur;
            while(i < s.size() && s[i] != ' ')
            {
                s[index++] = s[i++];
            }
            reverse(s.begin() + index - (i - cur), s.begin() + index);
            cur = i;
        }
        s.erase(s.begin() + index, s.end());
    }

};

int main()
{
    Solution s;
    string xxx = "   the   sky   is   blue   ";
    s.reverseWords(xxx);
    cout << xxx << endl;

    xxx = "   the   sky   is   blue   ";
    s.reverseWords1(xxx);
    cout << xxx << endl;
    return 0;
}
