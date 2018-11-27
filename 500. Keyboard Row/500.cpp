#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> rt;
        for(auto word : words)
        {
            for(auto row : keyboard)
            {
                if(word.find_first_not_of(row) == -1)
                {
                    rt.push_back(word);
                    break;
                }
            }
        }
        
        return rt;
    }
private:
    vector<string> keyboard = {"qwertyuiopQWERTYUIOP", "asdfghjklASDFGHJKL", "zxcvbnmZXCVBNM"};
};

int main()
{
    Solution s;
    vector<string> words = {"Hello", "Alaska", "Dad", "Peace"};
    vector<string> result = s.findWords(words);
    for(auto word : result)
        cout << word << endl;
    return 0;
}
