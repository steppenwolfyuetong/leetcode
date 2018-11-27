/*
This is a follow up of Shortest Word Distance. The only difference is now word1 could be the same as word2.

Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

word1 and word2 may be the same and they represent two individual words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “makes”, word2 = “coding”, return 1.
Given word1 = "makes", word2 = "makes", return 3.

Note:
You may assume word1 and word2 are both in the list.
*/

class Solution {
public:
    int shortest(vector<string> &words, string word) {
        int pre = -1, res = INT_MAX;
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            if (words[i] == word) {
                if (pre != -1) res = min(res, i - pre);
                pre = i;
            }
        }
        return res;
    }

    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        if (word1 == word2) 
            return shortest(words, word1);

        int pos1 = -1;
        int pos2 = -1;
        int rt = INT_MAX;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1) {
                pos1 = i;
            }
            else if (words[i] == word2) {
                pos2 = i;
            }
            if (pos1 != -1 and pos2 != -1) {
                rt = min(rt, abs(pos1 - pos2));
            }
        }
        return rt;
    }
};
