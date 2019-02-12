/*
Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
*/

#include <stack>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.size() != popped.size()) {
            return false;
        }

        stack<int> stk;
        int i = 0, j = 0;       // i is pushed index, j is popped index

        while (i < pushed.size()) {
            stk.push(pushed[i++]);
            while (!stk.empty() && stk.top() == popped[j]) {
                stk.pop();
                j++;
            }
        }

        return stk.empty();
    }
};

int main() {
    Solution s;
    //vector<int> pushed = {1,2,3,4,5};
    //vector<int> popped = {4,5,3,2,1};
    vector<int> pushed = {2,1,0};
    vector<int> popped = {1,2,0};
    cout << s.validateStackSequences(pushed, popped) << endl;
    return 0;
}
