#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
		vector<int>::reverse_iterator iter;
		// 反向迭代器声明为reverse_iterator
		// 同时 对于reverse_iterator ++代表向前迭代
		for(iter = digits.rbegin(); iter != digits.rend(); iter++)
		{
			if(iter == digits.rbegin())
				*iter += 1 + carry;
			else
				*iter += carry;
			if(*iter >= 10)
			{
				*iter -= 10;
				carry = 1;
			}
			else {
				carry = 0;}
		}
		if(carry == 1)
		{
			digits.insert(digits.begin(),1);
		}
		return digits;
    }
};

int main()
{
	Solution *s = new Solution;
	vector<int> a;
	for(int i = 1; i <= 9; i++)
		a.push_back(i);
	for(vector<int>::iterator iter = a.begin(); iter < a.end(); iter++)
		cout<<*iter<<' ';
	cout<<endl;
	s->plusOne(a);
	for(vector<int>::iterator iter = a.begin(); iter < a.end(); iter++)
		cout<<*iter<<' ';
	cout<<endl;
	return 0;
}
