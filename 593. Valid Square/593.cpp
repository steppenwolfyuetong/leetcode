class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        // 四边形 边长相等 对角线长度相等
        unordered_set<int> s({dis(p1, p2), dis(p2, p3), dis(p3, p4), dis(p4, p1), dis(p1, p3), dis(p2, p4)});
        return !s.count(0) && s.size() == 2;
    }

    int dis(vector<int> &p1, vector<int> &p2)
    {
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }
};
