#include<stack>
#include<vector>
#include<sstream>
#include<iostream>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(int i = 0; i < tokens.size(); i++)
        {
            if(tokens[i].size() != 1 || isdigit(tokens[i][0]))
			{
				stringstream ss;
				ss << tokens[i];
				int temp;
				ss >> temp;
				stk.push(temp);
			}
            else
            {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
				switch(tokens[i][0])
				{
					case '+':
						stk.push(b+a);
						break;
					case '-':
						stk.push(b-a);
						break;
					case '*':
						stk.push(b*a);
						break;
					case '/':
						stk.push(b/a);
						break;
				}
            }
        }
        return stk.top();
    }
};

int main()
{
	vector<string> rpn;
	rpn.push_back("4");
	rpn.push_back("-13");
	rpn.push_back("5");
	rpn.push_back("/");
	rpn.push_back("+");
	Solution *s = new Solution;
	cout<<s->evalRPN(rpn)<<endl;
	return 0;
}
