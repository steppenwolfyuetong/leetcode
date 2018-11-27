#include <string>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size() == k)
            return "0";

        stack<char> stk;
        for(int i = 0; i < num.size(); i++)
        {
            char ch = num[i];
            //whenever meet a digit which is less than the previous digit, discard the previous one
            while(k > 0 && !stk.empty() && stk.top() > num[i])
            {
                stk.pop();
                k--;
            }
            stk.push(num[i]);
        }

        while(k > 0)
        {
            stk.pop();
            k--;
        }

        string rt;
        while(!stk.empty())
        {
            rt += stk.top();
            stk.pop();
        }
        reverse(rt.begin(), rt.end());

        int index = 0;
        for(index = 0; index < rt.size(); index++)
        {
            if(rt[index] != '0')
            {
                break;
            }
        }

        return index == rt.size() ? "0" : rt.substr(index);
    }
};

int main()
{
    Solution *s = new Solution();
    string num = "100";
    int k = 1;
    cout << s->removeKdigits(num, k) << endl;
    return 0;
}
