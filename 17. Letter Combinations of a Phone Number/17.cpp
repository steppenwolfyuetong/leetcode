#include<vector>
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<string> letter;
	// dfs
    vector<string> letterCombinations(const string &digits) {
		vector<string> result;
		string cur;
		if(digits.size() == 0)
			return result;
		string arr[] = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
		for(int i = 0; i < 10; i++)
			letter.push_back(arr[i]);
        dfs(digits,0,cur,result);
        return result;
    }

    void dfs(const string& digits, int index, string& cur, vector<string>& result)
    {
        if(index == digits.size())
        {
            result.push_back(cur);
            return;
        }
        for(int i = 0; i < letter[digits[index]-'0'].size(); i++)
        {
            cur.append(1,letter[digits[index]-'0'][i]);
            dfs(digits,index+1,cur,result);
            cur.erase(cur.end()-1);
        }
    }
};

int main()
{
	Solution *s = new Solution;
	string tel = "23";
	vector<string> result = s->letterCombinations(tel);
	for(int i = 0; i < result.size(); i++)
		cout<<result[i]<<endl;
	return 0;
}
