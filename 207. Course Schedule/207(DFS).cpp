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
    /*
     * For DFS, it will first visit a node, then one neighbor of it, then one neighbor of this neighbor... and so on. 
     * If it meets a node which was visited in the current process of DFS visit, a cycle is detected and we will return false.
     * Otherwise it will start from another unvisited node and repeat this process till all the nodes have been visited.
     * Note that you should make two records: one is to record all the visited nodes and the other is to record the visited nodes in the current DFS visit.
     */
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);   //形成有向图
        vector<bool> visited(numCourses, false);
        for(int i = 0; i < numCourses; i++)
        {
            if(!dfs(graph, i, visited))
            {
                return false;
            }
        }
        return true;
    }
private:
    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>> &prerequisites)
    {
        vector<unordered_set<int>> graph(numCourses);
        for(auto pre : prerequisites)
        {
            graph[pre.second].insert(pre.first);
        }
        return graph;
    }


    // 判断是否存在环
    // 如果不存在 返回true
    // 如果存在环 返回false
    bool dfs(vector<unordered_set<int>> &graph, int index, vector<bool> &visited)
    {
        if(visited[index])
            return false;
        else
            visited[index] = true;

        for(auto endPoint : graph[index])
        {
            if(!dfs(graph, endPoint, visited))
            {
                return false;
            }
        }
        visited[index] = false;
        return true;
    }
};

int main()
{
    Solution *s = new Solution();
    int numCourses = 2;
    vector<pair<int, int>> prerequisites;
    prerequisites.push_back(make_pair(1,0));
    cout << s->canFinish(numCourses, prerequisites) << endl;
    return 0;
}
