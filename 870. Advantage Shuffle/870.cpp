class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        multiset<int> s(begin(A), end(A));
        vector<int> result;
        for (auto i = 0; i < B.size(); ++i) {
            auto it = s.upper_bound(B[i]);
            if (it == s.end()) {
                it = s.begin();
            }
            result.push_back(*it);
            s.erase(it);
        }
        return result;
    }

    // 田忌赛马
    vector<int> advantageCount(vector<int> A, vector<int> B) {
        map<int, int> m;
        for (int i : A) 
            m[i]++;

        map<int,int>::iterator it;
        vector<int> res;

        for (int i : B) {
            // 在A中找刚好比B打的元素 如果没有 就用最小的
            it = m.upper_bound(i);
            int x = it != m.end() ? it->first : m.begin()->first;
            if (--m[x] == 0) 
                m.erase(x);
            res.push_back(x);
        }
        return res;
    }
};
