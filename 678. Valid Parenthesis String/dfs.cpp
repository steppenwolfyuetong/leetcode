// length of s is in range [0,100], indicates a O(n^3)
//
// isValid(s, i, j): s[i, j] is valid or not
//
// case 1: L....R -> ....
// case 2: L...R*...* -> L...R, *...*
//         find some break point k, and slove sub problem [i, k] and [k + 1, j]

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int checkValidString(string s) {
        int n = s.size();
        cache_ = vector<vector<int>>(n, vector<int>(n, -1));
        return isValid(s, 0, n - 1);
    }

    bool isValid(const string &s, int i, int j) {
        if (i > j) {
            return true;
        }
        if (cache_[i][j] != -1) {
            return cache_[i][j];
        }
        if (i == j) {
            cache_[i][j] = s[i] == '*' ? true : false;
            return cache_[i][j];
        }

        if ((s[i] == '(' || s[i] == '*') && (s[j] == ')' || s[j] == '*') && isValid(s, i + 1, j - 1)) {
            cache_[i][j] = 1;
            return true;
        }
        
        for (int k = i; k < j; k++) {
            if (isValid(s, i, k) && isValid(s, k + 1, j)) {
                cache_[i][j] = 1;
                return true;
            }
        }

        cache_[i][j] = 0;
        return false;
    }

    vector<vector<int>> cache_;
};

int main() {
    Solution s;
    cout << s.checkValidString("(*))") << endl;
    cout << s.checkValidString("*(*(") << endl;
    cout << s.checkValidString("(*))()") << endl;
}
