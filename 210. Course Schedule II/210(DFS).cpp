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
    // DFS
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);   //形成有向图
        vector<bool> visited(numCourses, false);
        vector<bool> onpath(numCourses, false);
        vector<int> rt;
        for(int i = 0; i < numCourses; i++)
        {
            if(!visited[i])
                if(!dfs(graph, i, onpath, visited, rt))
                    return {};
        }
        reverse(rt.begin(), rt.end());
        return rt;
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
    // 如果不存在 添加至结果 返回true
    // 如果存在环 返回false
    bool dfs(vector<unordered_set<int>> &graph, int index, vector<bool> &onpath, vector<bool> &visited, vector<int> &rt)
    {
        if(visited[index])
            return true;

        onpath[index] = visited[index] = true;

        for(auto endPoint : graph[index])
        {
            // 存在环
            if(onpath[endPoint] || !dfs(graph, endPoint, onpath, visited, rt))
            {
                return false;
            }
        }
        rt.push_back(index);
        onpath[index] = false;
        return true;
    }
};

int main()
{
    Solution *s = new Solution();
    int numCourses = 4;
    vector<pair<int, int>> prerequisites;
    prerequisites.push_back(make_pair(1,0));
    prerequisites.push_back(make_pair(2,0));
    prerequisites.push_back(make_pair(3,1));
    prerequisites.push_back(make_pair(3,2));
    
    vector<int> rt = s->findOrder(numCourses, prerequisites);
    for(auto num : rt)
    	cout << num << endl;
    return 0;
}
