#include "../leetcode.h"

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i].first, b = equations[i].second;
            dict[a][b] = values[i];
            dict[b][a] = 1 / values[i];
            cache.insert(a);
            cache.insert(b);
        }
        
        vector<double> result;
        for (const auto& query : queries) {
            unordered_set<string> visited;
            result.emplace_back(calc(query.first, query.second, visited));
        }
        return result;
    }
    
    double calc(string a, string b, unordered_set<string> &visited) {
        if (visited.count(a)) {
            return -1.0;
        }

        visited.insert(a);
        if (!cache.count(a) || !cache.count(b)) {
            return -1.0;
        }
        if (a == b) {
            return 1.0;
        }
        if (dict.count(a) && dict[a].count(b)) {
            return dict[a][b];
        }

        for (const auto& kv : dict[a]) {
            string c = kv.first;
            double ac = kv.second;
            double cb = calc(c, b, visited);
            if (cb != -1.0) {
                dict[c][b] = cb;
                dict[b][c] = 1 / cb;
                return ac * cb;
            }
        }
        return -1.0;
    }
private:        
    unordered_map<string, unordered_map<string, double>> dict;
    set<string> cache;
};

int main() {
    Solution s;
    vector<pair<string, string>> equations = {{"a", "b"}, {"b", "c"}};
    vector<double> values = {2.0, 3.0};
    vector<pair<string, string>> queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};

    s.calcEquation(equations, values, queries);

    equations = {{"a","b"},{"c","d"}};
    values = {1.0,1.0};
    queries = {{"a","c"},{"b","d"},{"b","a"},{"d","c"}};
    s.calcEquation(equations, values, queries);
}
