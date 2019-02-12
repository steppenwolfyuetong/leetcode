class UnionFindSet {
public:
    // union two coordinate
    void Union(const string& stone1, const string& stone2) {
        string p1 = Find(stone1), p2 = Find(stone2);
        if (p1 == p2) {
            return;
        }
        parents_[p1] = p2;
        islands--;
    }

    // find the root stone
    const string& Find(const string& stone) {
        if (stone != parents_[stone]) {
            parents_[stone] = Find(parents_[stone]);
        }
        return parents_[stone];
    }

    unordered_map<string, string> parents_;
    int islands;
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        UnionFindSet ufs;
        for (const auto& stone : stones) {
            string s = to_string(stone[0]) + " " + to_string(stone[1]);
            ufs.parents_[s] = s;
        }
        ufs.islands = stones.size();

        for (const auto& s1 : stones) {
            string stone1 = to_string(s1[0]) + " " + to_string(s1[1]);
            for (const auto& s2 : stones) {
                if (s1[0] == s2[0] || s1[1] == s2[1]) {
                    string stone2 = to_string(s2[0]) + " " + to_string(s2[1]);
                    ufs.Union(stone1, stone2);
                }
            }
        }

        return stones.size() - ufs.islands;
    }
};

