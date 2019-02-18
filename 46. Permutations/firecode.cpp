#include <vector>
#include <string>
#include <iostream>
using namespace std;

// namespace std have been included for this problem.

void dfs(vector<string> &result, vector<bool> &visited, string s, string cur) {
    if (cur.size() == s.size()) {
        result.emplace_back(cur);
        return;
    }

    for (int i = 0; i < s.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            cur.push_back(s[i]);
            dfs(result, visited, s, cur);
            visited[i] = false;
            cur.pop_back();
        }
    }
}

// Add any helper functions(if needed) above.
vector<string>  get_permutations(string s) 
{
    vector<string> result;
    vector<bool> visited(s.size(), false);
    string cur;
    dfs(result, visited, s, cur);
    return result;
}

int main() {
    vector<string> result = get_permutations("abc");
    for (const auto& p : result) {
        cout << p << endl;
    }
    return 0;
}
