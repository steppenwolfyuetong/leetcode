#include <iostream>
#include <algorithm>
using namespace std;

/*
Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.

The input string does not contain leading or trailing spaces and the words are always separated by a single space.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Could you do it in-place without allocating extra space?
*/


class Solution
{
public:
    void reverseWords(string &s)
    {
        //两次反转
        //the sky is blue -> eulb si yks eht -> blue is the sky
        reverse(s,0,s.size() - 1);
        int index = 0;
        for(int i = 0; i <= s.size(); i++)
        {
            if(i == s.size() || s[i] == ' ')
            {
                reverse(s,index,i-1);
                index = i+1;
            }
        }
    }
private:
    void reverse(string &s, int left, int right)
    {
        while(left < right)
        {
            swap(s[left],s[right]);
            left++;
            right--;
        }
    }
};

int main()
{
    Solution sol;
    string s = "the sky is blue";
    sol.reverseWords(s);
    cout << s << endl;
    s = "hao wu liao a";
    sol.reverseWords(s);
    cout << s << endl;
}
