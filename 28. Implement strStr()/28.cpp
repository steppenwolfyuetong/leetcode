#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
		int m = haystack.length(), n = needle.length();
		if(!n)
			return 0;
        int i = 0, j = 0;
		while(i != m-n+1)
		{
			while(haystack[i+j] == needle[j])
			{
				j++;
			}
			//不知道为什么只要包含最后一个字符的匹配 即便的确为子串
			//也无法正确识别 string的最后不知道是如何实现 只得改为j>=n
			//if(j == n)
			if(j >= n)
			{
				return i;
			}
			i++;
			j = 0;
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
