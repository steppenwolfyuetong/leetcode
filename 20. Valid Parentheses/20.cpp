#include<stack>
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        bool flag1 = false, flag2 = false, flag3 = false;
        for(int i = 0; i < s.size() ; i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                stk.push(s[i]);
            if(s[i] == ')' || s[i] == ']' || s[i] == '}')
            {
                if(stk.empty())
                    return false;
                char top = stk.top();
				stk.pop();
                if(top == '(' && s[i] != ')' || top == '[' && s[i] != ']' || top == '{' && s[i] != '}')
					return false;
            }
        }
        return stk.empty();
    }
};

int main()
{
    Solution *s = new Solution;
    cout<<s->isValid("()[]{}");
    return 0;
}
    
