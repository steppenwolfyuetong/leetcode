#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    /*
    // dfs
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        const int m = obstacleGrid.size();
        const int n = obstacleGrid[0].size();
        this->cache = vector<vector<int> >(m + 1, vector<int>(n + 1, 0));
        return dfs(obstacleGrid, m, n);
    }
private:
    vector<vector<int> > cache;
    int dfs(vector<vector<int> >& obstacleGrid, int m, int n)
    {
        if(obstacleGrid[m-1][n-1])
            return 0;
        if(m < 1 || n < 1)
            return 0;
        if(m == 1 && n ==1)
            return 1;
        return update(obstacleGrid,m-1,n) + update(obstacleGrid,m,n-1);
    }

    int update(vector<vector<int> >& obstacleGrid, int m, int n)
    {
        if(cache[m][n])
            return cache[m][n];
        else
            return cache[m][n] = dfs(obstacleGrid,m,n);
    }
    */

    // dp
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int> > dp(m + 1, vector<int> (n + 1, 0));
        dp[0][1] = 1;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (!obstacleGrid[i - 1][j - 1])
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        return dp[m][n];
    } 


};

int main()
{
    Solution *s = new Solution;
    vector<vector<int> > obstacle;
    obstacle.push_back(vector<int>(3,0));
    obstacle.push_back(vector<int>(3,0));
    obstacle.push_back(vector<int>(3,0));
    obstacle[1][1] = 1;
    cout<<s->uniquePathsWithObstacles(obstacle)<<endl;
    return 0;
}
