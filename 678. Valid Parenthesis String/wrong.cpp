/*
    within first i characters
    balance[i]: (left - right) in s[0, i), once balance[i] < 0, return false
    asterisk[i]: * which has not used to balance parenthesis in s[0, i)

    i in range [1, s.size()]
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

// wrong, can't handle "*(*("
class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<int> balance(n + 1, 0);
        vector<int> asterisk(n + 1, 0);             // unused asterisk

        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == '(') {
                balance[i] = balance[i - 1] + 1;
                asterisk[i] = asterisk[i - 1];
            } else if (s[i - 1] == ')') {
                if (balance[i - 1] == 0 && asterisk[i - 1] == 0) {      // no more unused asterisk
                    return false;
                } else if (balance[i - 1] > 0) {                        // use '(' to balance first
                    balance[i] = balance[i - 1] - 1;
                    asterisk[i] = asterisk[i - 1];
                } else {                                                // treat asterisk as '('
                    asterisk[i] = asterisk[i - 1] - 1;
                }
            } else {
                balance[i] = balance[i - 1];
                asterisk[i] = asterisk[i - 1] + 1;
            }
        }

        cout << "balance: ";
        for (int k = 1; k <= n; k++) {
            cout << balance[k];
        }
        cout << endl;
        cout << "asterisk: ";
        for (int k = 1; k <= n; k++) {
            cout << asterisk[k];
        }
        cout << endl;

        if (balance[n] > 0 && asterisk[n] < balance[n]) {
            return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.checkValidString("*(*(") << endl;
    cout << s.checkValidString("(*))") << endl;
    cout << s.checkValidString("(*))()") << endl;
    cout << s.checkValidString("(*))*(*(") << endl;
}
