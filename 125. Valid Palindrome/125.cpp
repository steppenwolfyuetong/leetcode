#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        for(int i = 0; i != s.size(); i++)
            s[i] = tolower(s[i]);
        string::iterator iter1 = s.begin(), iter2 = s.end()-1;
        while(iter1 < iter2)
        {
			if(!isalnum(*iter1))
				iter1++;
			else if(!isalnum(*iter2))
				iter2--;
            else if(*iter1 != *iter2)
                return false;
			else
			{
				iter1++;
				iter2--;
			}
        }
		return true;
    }
};
 
int main()
{
    Solution *s = new Solution;
    string s1("A man, a plan, a canal: Panama");
	cout<<s->isPalindrome(s1);
}
