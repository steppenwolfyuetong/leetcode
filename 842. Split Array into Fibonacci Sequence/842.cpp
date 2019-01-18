#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> result;
        dfs(S, 0, result);
        return result;
    }

    bool dfs(const string &str, int start, vector<int> &result) {
        if (start == str.size()) {
            return result.size() >= 3 ? true : false;
        }

        for (int size = 1; size <= str.size() - start; size++) {
            if (str[start] == '0' && size > 1) {
                return false;
            }

            string cur = str.substr(start, size);
            long select = stol(cur);
            if (select > INT_MAX) {
                return false;
            }

            if (result.size() < 2) {
                result.emplace_back(select);
            } else if (*result.rbegin() + *(result.rbegin() + 1) == select){
                result.emplace_back(select);
            } else {
                continue;
            }

            if (dfs(str, start + size, result)) {
                return true;
            }

            result.pop_back();
        }
        return false;
    }
};

int main() {
    Solution *s = new Solution();
    auto wtf = [&] (string str) {
        vector<int> result = s->splitIntoFibonacci(str);
        for (const auto& num : result) {
            cout << num << " ";
        }
        cout << endl;
    };

    //wtf("123456579");
    //wtf("11235813");
    //wtf("112358130");
    //wtf("0123");
    //wtf("1101111");
    wtf("5511816597");
    return 0;
}
