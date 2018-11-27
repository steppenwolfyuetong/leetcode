#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> letter(256, 0);
        vector<bool> visited(256, false);
        string rt = "";

        for(char ch : s)
            letter[ch]++;

        for(char ch : s)
        {
            letter[ch]--;
            if(visited[ch])
                continue;

            if(!rt.empty())
            {
                while(ch < rt.back() && letter[rt.back()])
                {
                    visited[rt.back()] = false;
                    rt.pop_back();
                }
            }
            
            rt += ch;
            visited[ch] = true;
        }
        return rt;
    }
};

int main()
{
    Solution *s = new Solution();
    string str;
    /*
    str = "bcabc";
    cout << s->removeDuplicateLetters(str) << endl;
    str = "cbacdcbc";
    cout << s->removeDuplicateLetters(str) << endl;
    */
    str = "cbbbcaa";
    cout << s->removeDuplicateLetters(str) << endl;
    return 0;
}
