// S will be a string with length between 1 and 12.
// which implies the algorithm can be brute force search, O(2^n), each letter can be upper or lower

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> result;
        string cur;
        dfs(S, 0, cur, result);
        return result;
    }

    void dfs(string &str, int start, string cur, vector<string> &result) {
        if (start == str.size()) {
            result.emplace_back(cur);
            return;
        }
        
        if (isdigit(str[start])) {
            cur += str[start];
            dfs(str, start + 1, cur, result);
        } else {
            cur += str[start];
            dfs(str, start + 1, cur, result);           // don't transform
            cur.pop_back();

            // could toggle letter with ^, cur += (str[start] ^= (1 << 5));
            if (isupper(str[start])) {
                cur += tolower(str[start]);
            } else {
                cur += toupper(str[start]);
            }
            dfs(str, start + 1, cur, result);
            cur.pop_back();
        }
    }
};
