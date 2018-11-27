
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
    // BFS
    /*
     * BFS uses the indegrees of each node. We will first try to find a node with 0 indegree.
     * If we fail to do so, there must be a cycle in the graph and we return false. Otherwise we have found one. 
     * We set its indegree to be -1 to prevent from visiting it again and reduce the indegrees of all its neighbors by 1. 
     * This process will be repeated for n (number of nodes) times. 
     * If we have not returned false, we will return true.
     */
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);   //形成有向图
        vector<int> indegrees = calculate_indegree(graph);                          //求入度

        for(int i = 0; i < numCourses; i++)
        {
            int j = 0;
            for(; j < numCourses; j++)
            {
                if(indegrees[j] == 0)
                {
                    break;
                }
            }

            if(j == numCourses)
                return false;

            indegrees[j] = -1;
            for(auto endPoint : graph[j])
            {
                indegrees[endPoint]--;
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

    vector<int> calculate_indegree(vector<unordered_set<int>> &graph)
    {
        vector<int> indegrees(graph.size(), 0);
        for(int index = 0; index < graph.size(); index++)
        {
            for(auto endPoint : graph[index])
            {
                indegrees[endPoint]++;
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
    cout << s->canFinish(numCourses, prerequisites) << endl;
    return 0;
}
