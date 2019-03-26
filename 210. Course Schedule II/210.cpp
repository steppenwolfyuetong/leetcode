/*
 * 参见笔记
 * 拓扑排序问题
 * 即看是不是一个有向无环图
 * 先转换为图 用一个vector<unordered_set<int>>表示
 */

#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    // see 269. Alien Dictionary
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);   //形成有向图
        vector<int> indegrees = calculate_indegree(graph);                          //求入度

        vector<int> rt;
        while (rt.size() < numCourses) {
            bool found = false;
            for (int i = 0; i < indegrees.size(); i++) {
                if (indegrees[i] == 0) {
                    found = true;
                    rt.emplace_back(i);
                    indegrees[i] = -1;
                    for (auto neighbor : graph[i]) {
                        indegrees[neighbor]--;
                    }
                    break;
                }
            }
            if (!found) {
                return {};
            }
        }
		
        return rt;
    }
private:
    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>> &prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for(auto pre : prerequisites) {
            graph[pre.second].insert(pre.first);
        }
        return graph;
    }

    vector<int> calculate_indegree(vector<unordered_set<int>> &graph) {
        vector<int> indegrees(graph.size(), 0);
        for(int i = 0; i < graph.size(); i++) {
            for (const auto& neighbor : graph[i]) {
                indegrees[neighbor]++;
            }
        }
        return indegrees;
    }
};

int main()
{
    Solution *s = new Solution();
    int numCourses = 2;
    vector<pair<int, int>> prerequisites;
    prerequisites.push_back(make_pair(1,0));
    
    vector<int> rt = s->findOrder(numCourses, prerequisites);
    for(auto num : rt)
    	cout << num << endl;
    return 0;
}
