#include<string>
#include<iostream>
using namespace std;

// *Æ¥Åä¾¡Á¿ÉÙµÄ´®
class Solution {
public:
    bool isMatch(string s, string p) {
		int m = s.size(), n = p.size();
		int flag = 0, i = 0, j = 0, nextIndex = 0, lastAsterisk = -1;
		while(i < m)
		{
			cout<<i<<' '<<s[i]<<' '<<j<<' '<<p[j]<<' '<<nextIndex<<' '<<lastAsterisk<<endl;
			// advancing both pointers when (both characters match) or ('?' found in pattern)
            // note that *p will not advance beyond its length
			if(s[i] == p[j] || p[j] == '?')
			{
				i++; j++; continue;
			}
			// * found in pattern, track index of *, only advancing pattern pointer
			if(p[j] == '*')
			{
				nextIndex = i;
				lastAsterisk = j;
				j++;
				continue;
			}
			// current characters didn't match
			// last pattern pointer was *, current pattern pointer is not *
            // only advancing pattern pointer
			if(lastAsterisk != -1)
			{
				i = nextIndex;
				nextIndex++;
				j = lastAsterisk + 1;
				continue;
			}	
			// current pattern pointer is not star, last pattern pointer was not *
            // characters do not match
			return false;
		}
		// check for remaining characters in pattern
		while(p[j] == '*')
			j++;
		return j == n;
    }
};


int main()
{
    Solution *s = new Solution;
//	string s1("c"),s2("*?*");
	string s1("abefcdgiescdfimde"),s2("ab*cd?i*de");
	//         ab*cd?i*de
	//         0123456789
	cout<<s->isMatch(s1,s2);
}


