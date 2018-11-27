/*
 *
  Pacific ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * Atlantic
 */

#include <limits.h>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

#define PACIFIC  1
#define ATLANTIC 2


// dfs
class Solution {
public:
    vector<pair<int, int> > pacificAtlantic(vector<vector<int> >& matrix) {
        vector<pair<int, int> > rt;
        if(matrix.empty() || matrix.size() <= 0 || matrix[0].size() <= 0)
            return rt;

        m_visited.resize(matrix.size(), vector<int>(matrix[0].size(), 0));
        m_dir.push_back(make_pair(-1,  0));
        m_dir.push_back(make_pair( 1,  0));
        m_dir.push_back(make_pair( 0, -1));
        m_dir.push_back(make_pair( 0,  1));

        // left and right edges
        for(int i = 0; i < matrix.size(); i++)
        {
            dfs(matrix, i, 0, INT_MIN, PACIFIC);
            dfs(matrix, i, matrix[0].size() - 1, INT_MIN, ATLANTIC);
        }
        // up and down edges
        for(int j = 0; j < matrix[0].size(); j++)
        {
            dfs(matrix, 0, j, INT_MIN, PACIFIC);
            dfs(matrix, matrix.size() - 1, j, INT_MIN, ATLANTIC);
        }

        for(int i = 0; i < m_visited.size(); i++)
        {
            for(int j = 0; j < m_visited[0].size(); j++)
            {
                if(m_visited[i][j] == PACIFIC + ATLANTIC)        // both visited
                {
                    rt.push_back(make_pair(i, j));
                }
            }
        }
        return rt;
    }

    /*
     * (x, y): coordinates of grid
     * height: the height of previous grid, if the previous height < current height, water can not flow over
     * flag: 1 means pacific, 2 means atlantic, if the grid can be visted, it will add to the cell of m_visited
     *       in m_visited, the value could be 0(None), 1(Pacific visited), 2(Atlantic visited), 3(Both visited)
     */
    void dfs(vector<vector<int> >& matrix, int x, int y, int height, int flag)
    {
        if(x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size())
            return;
        if(height > matrix[x][y] || (m_visited[x][y] & flag))
            return;
        
        m_visited[x][y] |= flag;

        for(auto dir : m_dir)
        {
            dfs(matrix, x + dir.first, y + dir.second, matrix[x][y], flag);
        }
        return;
    }
private:
    vector<vector<int> > m_visited;     // whether the grid has been visited
    vector<pair<int, int> > m_dir;      // four direction
};

// bfs: add the neighbour cell with height >= current cell to the queue and marked as visited
class SolutionBFS
{
public:
    vector<pair<int, int> > pacificAtlantic(vector<vector<int> >& matrix) {
        vector<pair<int, int> > rt;
        if(matrix.empty() || matrix[0].empty())
            return rt;

        m_visited.resize(matrix.size(), vector<int>(matrix[0].size(), 0));
        m_dir.push_back(make_pair(-1,  0));
        m_dir.push_back(make_pair( 1,  0));
        m_dir.push_back(make_pair( 0, -1));
        m_dir.push_back(make_pair( 0,  1));

        for(int i = 0; i < matrix.size(); i++)
        {
            m_pacific.push(make_pair(i, 0));
            m_visited[i][0] |= PACIFIC;
            m_atlantic.push(make_pair(i, matrix[0].size() - 1));
            m_visited[i][matrix[0].size() - 1] |= ATLANTIC;
        }
        for(int j = 0; j < matrix[0].size(); j++)
        {
            m_pacific.push(make_pair(0, j));
            m_visited[0][j] |= PACIFIC;
            m_atlantic.push(make_pair(matrix.size() - 1, j));
            m_visited[matrix.size() - 1][j] |= ATLANTIC;
        }

        bfs(matrix, m_pacific, PACIFIC);
        bfs(matrix, m_atlantic, ATLANTIC);

        for(int i = 0; i < m_visited.size(); i++)
        {
            for(int j = 0; j < m_visited[0].size(); j++)
            {
                if(m_visited[i][j] == PACIFIC + ATLANTIC)        // both visited
                {
                    rt.push_back(make_pair(i, j));
                }
            }
        }
        return rt;
    }

    void bfs(vector<vector<int> >& mat, queue<pair<int, int> >& que, int flag)
    {
        while(!que.empty())
        {
            pair<int, int> cur = que.front();
            que.pop();
            for(auto dir : m_dir)
            {
                int x = cur.first + dir.first, y = cur.second + dir.second;
                if(x < 0 || x >= mat.size() || y < 0 || y >= mat[0].size())
                    continue;
                if(mat[cur.first][cur.second] > mat[x][y] || (m_visited[x][y] & flag))
                    continue;

                m_visited[x][y] |= flag;
                que.push(make_pair(x, y));
            }
        }
    }
private:
    vector<vector<int> > m_visited;     // whether the grid has been visited
    vector<pair<int, int> > m_dir;      // four direction
    queue<pair<int, int> > m_pacific;
    queue<pair<int, int> > m_atlantic;
};


int main()
{
    vector<vector<int> > mat;
    int arr[5][5] = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    for(int i = 0; i < 5; i++)
    {
        mat.push_back(vector<int>());
        for(int j = 0; j < 5; j++)
        {
            mat[i].push_back(arr[i][j]);
        }
    }

    Solution *dfs = new Solution();
    vector<pair<int, int> > rt = dfs->pacificAtlantic(mat);
    cout << "dfs result:" << endl;
    for(int i = 0; i < rt.size(); i++)
    {
        cout << rt[i].first << ' ' << rt[i].second << endl;
    }

    /*
    SolutionBFS *bfs = new SolutionBFS();
    rt = bfs->pacificAtlantic(mat);
    cout << "bfs result:" << endl;
    for(int i = 0; i < rt.size(); i++)
    {
        cout << rt[i].first << ' ' << rt[i].second << endl;
    }
    */

    return 0;
}
