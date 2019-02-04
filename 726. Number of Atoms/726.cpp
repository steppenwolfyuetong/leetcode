#include <string>
#include <map>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    string countOfAtoms(string formula) {
        stack<map<string, int>> stk;
        map<string, int> cur;

        for (int i = 0; i < formula.size(); ) {
            if (formula[i] == '(') {
                stk.push(move(cur));
                cur = map<string,int>();
                ++i;
            } else if (formula[i] == ')') {
                int index = i + 1;
                int count = 0;
                while (index < formula.size() && isdigit(formula[index])) {
                    count = count * 10 + formula[index] - '0';
                    index++;
                }

                count = max(count, 1);
                for (auto p : cur) {
                    stk.top()[p.first] += p.second * count;
                }

                cur = move(stk.top());
                stk.pop();

                i = index;
            } else {
                int index = i + 1;
                while (index < formula.size() && islower(formula[index])) {
                    index++;
                }
                string ele = formula.substr(i, index - i);

                int count = 0;
                while (index < formula.size() && isdigit(formula[index])) {
                    count = count * 10 + formula[index] - '0';
                    index++;
                }
                count = max(count, 1);
                cur[ele] += count;

                i = index;
            }
        }

        string ans;
        for (auto p : cur) {
            ans += p.first;
            if (p.second > 1) ans += to_string(p.second);
        }

        return ans;
    }
};

int main() {
    Solution s;
    cout << s.countOfAtoms("Mg(OH)2") << endl;
    return 0;
}
