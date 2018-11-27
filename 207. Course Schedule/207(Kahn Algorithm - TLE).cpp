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
    // Kahn's algorithm
    // 耗时较长原因 不停在遍历graph 而BFS只用遍历一次
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);   //形成有向图
        vector<int> indegrees = calculate_indegree(graph);                          //求入度
		
        // 维护一个入度为0的set
        unordered_set<int> zeroIndegrees;
        for(int i = 0; i < indegrees.size(); i++)
        {
            if(indegrees[i] == 0)
            {
                zeroIndegrees.insert(i);
            }
        }
        
        while(!zeroIndegrees.empty())
        {
            int courseNum = *(zeroIndegrees.begin()); 
            zeroIndegrees.erase(courseNum);
            indegrees[courseNum] = -1;                                  // 入度置为-1表示已经访问过
            //cout << "cur:" << courseNum << endl;
            for(int index = 0; index < graph.size(); index++)
            {
                if(graph[index].find(courseNum) != graph[index].end())  // 存在从courseNum指向index的边 将其删除
                {
                	//cout << "delete in " << index << endl;
                    graph[index].erase(courseNum);
                }
                if(graph[index].empty() && indegrees[index] != -1)      // index的入度为0 且没有被加入至zeroIndegrees中过 添加至入度为0的set中
                {
                	//cout << "insert " << index << endl;
                    zeroIndegrees.insert(index);
                }
            }
        }
        
        for(int index = 0; index < graph.size(); index++)
        {
            if(!graph[index].empty())
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
            graph[pre.first].insert(pre.second);
        }
        return graph;
    }

    vector<int> calculate_indegree(vector<unordered_set<int>> &graph)
    {
        vector<int> indegrees(graph.size(), 0);
        for(int index = 0; index < graph.size(); index++)
        {
            indegrees[index] = graph[index].size();
        }
        return indegrees;
    }

    void display(unordered_set<int> &nums)
    {
    	for(auto num : nums)
    		cout << num << ' ';
    	cout << endl;
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
