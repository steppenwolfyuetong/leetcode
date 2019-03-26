/*
There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. 
You receive a list of words from the dictionary, where words are sorted lexicographically by the rules of this new language. 
Derive the order of letters in this language.

For example,
Given the following words in dictionary,

[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]
The correct order is: "wertf".

Note:
* You may assume all letters are in lowercase.
* If the order is invalid, return an empty string.
* There may be multiple valid order of letters, return any one of them is fine.
*/

// sorted lexicographically, so we can 
// for example, wrt < wrf, so 't' comes first before 'f'
//              wrf < er       w                      e

#include "../leetcode.h"

class Solution {
public:
    // Topological sort
    // similar to 210. Course schedule II
    string alienOrder(vector<string>& words) {
        if (words.empty()) {
            return "";
        }
        unordered_map<char, int> indegree;                          // indegree of each character
        unordered_map<char, unordered_set<char>> graph;             // dag
        for (const auto& word : words) {
            for (const auto& ch : word) {
                indegree[ch] = 0;
            }
        }

        for (int i = 0; i < words.size() - 1; i++) {
            int len = min(words[i].size(), words[i + 1].size());
            int j = 0;
            while (j < len) {
                if (words[i][j] != words[i + 1][j]) {               // find the first compare doesn't equal
                    break;
                }
                j++;
            }
            if (j < len) {
                indegree[words[i + 1][j]]++;                        // so according to topologial sort
                graph[words[i][j]].insert(words[i + 1][j]);         // words[i][j] must comes first before words[i+1][j]
            }
        }

        string result;
        while (result.size() < indegree.size()) {
            bool found = false;
            for (auto kv : indegree) {                              // find a node with indegree == 0
                if (kv.second == 0) {
                    found = true;
                    result += kv.first;
                    indegree[kv.first]--;                           // set node visited to avoid select it again
                    for (auto neighbor : graph[kv.first]) {         // decrease all neighbor's indegree of kv.first
                        indegree[neighbor]--;
                    }
                    break;
                }
            }
            if (!found) {                                           // threre are not valid node, impossible to sort
                return "";
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<string> words = {"wrt", "wrf", "er", "ett", "rftt"};
    cout << s.alienOrder(words) << endl;
    words = {"z", "x"};
    cout << s.alienOrder(words) << endl;
    words = {"z", "x", "z"};
    cout << s.alienOrder(words) << endl;
}
