#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string::reverse_iterator iter1 = a.rbegin(), iter2 = b.rbegin();
		int carry = 0, ai = 0, bi = 0, digit = 0;
		string result;
		while(iter1 != a.rend() && iter2 != b.rend())
		{
			ai = *iter1 - '0';
			bi = *iter2 - '0';
			digit = (ai + bi + carry) % 2;
			carry = (ai + bi + carry) / 2;
			result.insert(result.begin(),digit+'0');
			iter1++;
			iter2++;
		}
		while(iter1 != a.rend())
		{
			ai = *iter1 - '0';
			digit = (ai + carry) % 2;
			carry = (ai + carry) / 2;
			result.insert(result.begin(),digit+'0');
			iter1++;
		}
		while(iter2 != b.rend())
		{
			bi = *iter2 - '0';
			digit = (bi + carry) % 2;
			carry = (bi + carry) / 2;
			result.insert(result.begin(),digit+'0');
			iter2++;
		}
		if(carry)
			result.insert(result.begin(),'1');
		return result;
    }
};  

int main()
{
    Solution *s = new Solution;
    string s1("10101"),s2("11111");
	cout<<s->addBinary(s1,s2);
}
