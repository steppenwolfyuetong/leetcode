#include<string>
#include<iostream>
using namespace std;

// 递归             
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty())
            return s.empty();

        cout << s << ' ' << p << endl;

        bool first_match = false;
        if(!s.empty() && (s[0] == p[0] || p[0] == '.'))
            first_match = true;

        if(p.size() >= 2 && p[1] == '*')
        {
            //                                          *匹配至少1个字符
            //     (    *匹配0个字符        || (第一个字符匹配 && 后面的匹配))
            return (isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p)));
        }
        else
        {
            return first_match && isMatch(s.substr(1), p.substr(1));
        }
    }
};





int main()
{
    Solution *s = new Solution;
    string s1("aab"),s2("c*a*b");
	cout << s->isMatch(s1,s2) << endl;
}

