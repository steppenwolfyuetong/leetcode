// You may assume that each word will contain only lower case letters. 
// So we can use each bit of an int to indicate whether word[i] contains certain letter

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> dict(words.size(), 0);
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                dict[i] |= 1 << (words[i][j] - 'a');
            }
        }

        int result = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if ((dict[i] & dict[j]) == 0) {
                    result = max(result, static_cast<int>(words[i].size() * words[j].size()));
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<string> words = {"abcw","baz","foo","bar","xtfn","abcdef"};
    cout << s.maxProduct(words) << endl;
    return 0;
}
