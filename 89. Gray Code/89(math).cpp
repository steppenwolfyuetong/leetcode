#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
		int size = 1 << n;
		for(int i = 0; i < size; i++)
			result.push_back(binary2gray(i));
		return result;
    }
private:
	int binary2gray(int n)
	{
		return n ^ (n >> 1);
	}
};

int main()
{
	Solution *s = new Solution;
	vector<int> ans = s->grayCode(3);
	for(vector<int>::iterator iter = ans.begin(); iter < ans.end(); iter++)
		cout<<*iter<<' ';
	cout<<endl;
	return 0;
}
