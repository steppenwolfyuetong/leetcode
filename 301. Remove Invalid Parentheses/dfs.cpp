/*
Input: "()())()"
Output: ["()()()", "(())()"]
*/

#include <unordered_set>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        // will have duplicate result, so need to use set
        unordered_set<string> result;
        string cur("");
        dfs(0, cur, s, result);
        return {result.begin(), result.end()};
    }

    void dfs(int index, string cur, string &s, unordered_set<string>& result) {
        if (index == s.size()) {
            if(valid(cur) == 0) {
                if (result.empty() || (*result.begin()).size() == cur.size()) {
                    result.insert(cur);
                } else if ((*result.begin()).size() < cur.size()) {
                    result.clear();
                    result.insert(cur);
                }
            }
            return;
        }

        dfs(index + 1, cur, s, result);

        if (s[index] == '(') {
            cur += '(';
            dfs(index + 1, cur, s, result);
        } else if (s[index] == ')'){
            cur += ')';
            if (valid(cur) >= 0) {
                dfs(index + 1, cur, s, result);
            }
        } else {
            cur += s[index];
            dfs(index + 1, cur, s, result);
        }

        return;
    }

    int valid(string &s) {
        int balance = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                balance++;
            } else if (s[i] == ')') {
                balance--;
            }

            if (balance < 0) {
                return -1;
            }
        }
        return balance;
    }
};

int main() {
    Solution *s = new Solution();
    vector<string> result = s->removeInvalidParentheses("()())()");
    for (auto& s : result) {
        cout << s << endl;
    }
    return 0;
}
