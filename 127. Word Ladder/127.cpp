#include <queue>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }

        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        int dist = 1;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string cur = q.front();
                q.pop();
                if (cur == endWord) {
                    return dist;
                }
                helper(cur, dict, q);
            }
            dist++;
        }
        return 0;
    }
private:
    void helper(string word, unordered_set<string>& dict, queue<string>& que) {
        for (size_t i = 0; i < word.size(); i++) {
            string transformed = word;
            for (char letter = 'a'; letter <= 'z'; letter++) {
                transformed[i] = letter;
                if (dict.find(transformed) != dict.end()) {
                    que.push(transformed);
                    dict.erase(transformed);
                }
            }
        }
    }
};

int main() {
    Solution *s = new Solution();
    vector<string> wordList{"hot","dot","dog","lot","log","cog"};
    cout << s->ladderLength("hit", "cog", wordList) << endl;
    wordList = {"hot","dot","dog","lot","log"};
    cout << s->ladderLength("hit", "cog", wordList) << endl;
    return 0;
}
