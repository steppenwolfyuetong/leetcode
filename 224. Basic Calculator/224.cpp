#include <stack>
#include <cctype>
#include <iostream>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> num, op;
        int cur = 0, sign = 1, rt = 0;

        for(int i = 0; i < s.size(); i++)
        {
            if(isdigit(s[i]))
            {
                cur = cur * 10 + s[i] - '0';
            }
            else
            {
                rt += sign * cur;
                cur = 0;
                switch(s[i])
                {
                    case '+':
                        sign = 1;
                        break;
                    case '-':
                        sign = -1;
                        break;
                    case '(':
                        num.push(rt);
                        op.push(sign);
                        rt = 0;
                        sign = 1;
                        break;
                    case ')':
                        rt = num.top() + op.top() * rt;
                        num.pop();
                        op.pop();
                        break;
                }
            }
        }
        rt += sign * cur;
        return rt;
    }
};

int main()
{
    Solution *s = new Solution();
    cout << s->calculate("1 + 1") << endl;
    cout << s->calculate("2 - 1 + 2") << endl;
    cout << s->calculate("(1+(4+5+2)-3)+(6+8)") << endl;

}
