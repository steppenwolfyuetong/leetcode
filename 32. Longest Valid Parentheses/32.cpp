#include<stack>
#include<iostream>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        // last is the position of the last ')"
        int ans = 0, last = -1;
        // store all the indices of '('
        stack<int> stk;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                stk.push(i);
            } else {  
                // there is no matching '("
                if(stk.empty()) {
                    last = i;
                } else {
                    stk.pop();
                    if(stk.empty()) {
                        ans = max(ans,i-last);
                    } else {
                        ans = max(ans,i-stk.top());
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution *s = new Solution;
    cout<<s->longestValidParentheses("())()(()");
    return 0;
}
