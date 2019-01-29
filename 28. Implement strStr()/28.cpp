#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
		int m = haystack.length(), n = needle.length();
		if (!n) {
			return 0;
        }
        int i = 0, j = 0;
		while (i <= m - n)
		{
            j = 0;
            // j can't be greater than n, otherwise it's undefined
			while (j < n && haystack[i + j] == needle[j]) {
				j++;
			}

			if(j == n) {
				return i;
			}

			i++;
		}
		return -1;
    }
};

int main()
{
    Solution *s = new Solution;
    string s1("Helloworld"),s2("world");
	cout<<s->strStr(s1,s2);
}
