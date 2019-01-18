class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> result;
        map<int, int> lastIndex;
        for (int i = 0; i < S.size(); i++) {
            lastIndex[S[i]] = i;
        }

        int start = 0, end = 0;
        for (int i = 0; i < S.size(); i++) {
            end = max(end, lastIndex[S[i]]);
            if (end == i) {
                result.emplace_back(end - start + 1);
                start = end + 1;
            }
        }
        return result;
    }
};
