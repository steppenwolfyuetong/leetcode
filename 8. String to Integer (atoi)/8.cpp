#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int ans = 0, i = 0, n = str.size();
		bool flag = 1;
		while(isspace(str[i]) && i < n)
			i++;
		if(str[i] == '-')
		{
			flag = 0;
			i++;
		}
		else if(str[i] == '+')
		{
			flag = 1;
			i++;
		}
		for(; i < n; i++)
		{
			if(!isdigit(str[i]))
				break;
			else
			{
				if(ans > INT_MAX / 10 || (ans == INT_MAX/10 && (str[i] - '0') > INT_MAX % 10))
					return flag == 1 ? INT_MAX : INT_MIN;
				ans = ans * 10 + str[i] - '0';
			}
		}
		if(!flag)
			ans *= -1;
		return ans;
    }
};

int main()
{
    Solution *s = new Solution;
    string s1("  +123  ");
	cout<<s->myAtoi(s1);
}
