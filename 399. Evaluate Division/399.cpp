#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
private:
    unordered_map<string, unordered_map<string, double> > cache;
public:
    vector<double> calcEquation(vector<pair<string, string> > equations, vector<double>& values, vector<pair<string, string> > queries) {
        vector<double> rt;
        initCache(equations, values);
        for(int i = 0; i < queries.size(); i++)
        {
            unordered_set<string> path;
            double res = dfs(queries[i].first, queries[i].second, path);
            if(res == 0)
                rt.push_back(-1.0);
            else
                rt.push_back(res);
        }
        return rt;
    }

    void initCache(vector<pair<string, string> > &equations, vector<double>& values)
    {
        for(int i = 0; i < equations.size(); i++)
        {
            cache[equations[i].first].insert(make_pair(equations[i].second, values[i]));
            if(values[i] != 0)
                cache[equations[i].second].insert(make_pair(equations[i].first, 1 / values[i]));
        }
    }
    
    //a/b = a/c * ... * c/b
    double dfs(string a, string b, unordered_set<string> &path)
    {
        if(cache.find(a) == cache.end())
            return 0.0;
        if(cache[a].find(b) != cache[a].end())
            return cache[a][b];
        if(a == b)
            return 1.0;

        for(auto c : cache[a])
        {
            if(path.find(c.first) != path.end())
                continue;
            path.insert(c.first);
            double mid = dfs(c.first, b, path);
            if(mid)
                return c.second * mid;
        }
        return 0.0;
    }
};

int main()
{
    vector<pair<string, string> > equations;
    equations.push_back(make_pair("a","b"));
    equations.push_back(make_pair("b","c"));
    vector<double> values;
    values.push_back(2.0);
    values.push_back(3.0);
    vector<pair<string, string> > queries;
    queries.push_back(make_pair("a","c"));
    queries.push_back(make_pair("b","a"));
    queries.push_back(make_pair("a","e"));
    queries.push_back(make_pair("a","a"));
    queries.push_back(make_pair("x","x"));

    Solution *s = new Solution();
    vector<double> result = s->calcEquation(equations, values, queries);
    for(int i = 0; i < result.size(); i++)
        cout << result[i] << endl;
    return 0;
}

/*
equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ].
*/
