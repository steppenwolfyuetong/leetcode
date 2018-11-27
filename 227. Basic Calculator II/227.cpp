#include <cctype>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int cur = 0, top = 0, op = '+';
        for(int i = 0; i < s.size(); i++)
        {
            if(isdigit(s[i]))
                cur = cur * 10 + s[i] - '0';
            if( (!isdigit(s[i]) && !isspace(s[i])) || i == s.size() - 1)
            {
                switch(op)
                {
                    case '+':
                        stk.push(cur);
                        break;
                    case '-':
                        stk.push(-cur);
                        break;
                    case '*':
                        top = stk.top();
                        stk.pop();
                        stk.push(top * cur);
                        break;
                    case '/':
                        top = stk.top();
                        stk.pop();
                        stk.push(top / cur);
                        break;
                }
                cur = 0;
                op = s[i];
            }
        }
        
        int rt = 0;
        while(!stk.empty())
        {
            rt += stk.top();
            stk.pop();
        }
        return rt;
    }
};

int main()
{
    Solution s;
    cout << s.calculate("3 + 2 * 2") << endl;
}
