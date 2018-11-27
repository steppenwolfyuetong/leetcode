
#include <map>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> dict;
        for(int i = 0; i < magazine.size(); i++)
        {
            dict[magazine[i]]++;
        }

        for(int i = 0; i < ransomNote.size(); i++)
        {
            if(--dict[ransomNote[i]] < 0)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution *s = new Solution;
    string ransomNote = "aa";
    string magazine = "aab";
    cout << s->canConstruct(ransomNote, magazine) << endl;
    return 0;
}
