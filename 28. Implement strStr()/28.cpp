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
			//��֪��ΪʲôֻҪ�������һ���ַ���ƥ�� �����ȷΪ�Ӵ�
			//Ҳ�޷���ȷʶ�� string�����֪�������ʵ�� ֻ�ø�Ϊj>=n
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
