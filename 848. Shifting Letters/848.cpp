class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        for (int i = shifts.size() - 2; i > -1; i--) {
            shifts[i] = (shifts[i] + shifts[i + 1]) % 26;
        }

        string result = S;
        for (int i = 0; i < shifts.size(); i++) {
            result[i] = (result[i] - 'a' + shifts[i]) % 26 + 'a';
        }
        return result;
    }
};
