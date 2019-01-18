class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> stk;

        int result = 0;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '(') {
                stk.push(S[i]);
            } else if (!stk.empty()) {          // S[i] is ')', check if has unmatched '('
                stk.pop();
            } else {
                result++;                       // need to add a '('
            }
        }

        while (!stk.empty()) {
            stk.pop();
            result++;
        }
        return result;
    }
};
