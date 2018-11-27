#include<map>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        map<string,vector<string> > letter;
		for(vector<string>::iterator iter = strs.begin(); iter != strs.end(); iter++)
		{
            string key = *iter;
            sort(key.begin(),key.end());
            letter[key].push_back(*iter);
        }
        vector<string> result;
        for(map<string,vector<string> >::iterator iter = letter.begin(); iter != letter.end(); iter++)
        {
            if(iter->second.size() > 1)
            {
                result.insert(result.end(),iter->second.begin(),iter->second.end());
            }
        }
        return result;
    }
};

int main()
{
	Solution *s = new Solution;
	vector<string> str;
	str.push_back("abcd");
	str.push_back("adbc");
	s->anagrams(str);
}
