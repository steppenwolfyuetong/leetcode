/*
s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/

#include <stack>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string rt;
        stack<pair<int, string> > stk;
        int times = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '[')
            {
                if(times == 0)
                    times = 1;
                cout << "Times: " << times << endl;
                stk.push(make_pair(times,""));
                times = 0;
            }
            else if(s[i] == ']')
            {
                pair<int, string> ele = stk.top();
                stk.pop();
                for(int count = 0; count < ele.first; count++)
                {
                    if(stk.empty())
                        rt += ele.second;
                    else
                        stk.top().second += ele.second;
                }
            }
            else if(isdigit(s[i]))
            {
                times = times * 10 + (s[i] - '0');
            }
            else
            {
                if(stk.empty())
                    rt += s[i];
                else
                    stk.top().second += s[i];
            }
        }
        return rt;
    }
};

int main()
{
    Solution *sol = new Solution();
    string s = "2[abc]3[cd]ef";
    cout << s << endl;
    cout << sol->decodeString(s) << endl;
    s = "3[a2[c]]";
    cout << s << endl;
    cout << sol->decodeString(s) << endl;
    return 0;
}
