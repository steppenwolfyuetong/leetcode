/*
If out of bottom border (row >= m) then row = m - 1; col += 2; change walk direction.
if out of right border (col >= n) then col = n - 1; row += 2; change walk direction.
if out of top border (row < 0) then row = 0; change walk direction.
if out of left border (col < 0) then col = 0; change walk direction
*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> rt;
        if(matrix.empty() || matrix[0].empty())
            return rt;

        int m = matrix.size(), n = matrix[0].size();
        int x = 0, y = 0;
        pair<int, int> dir = make_pair(-1, 1);
        for(int i = 0; i < m * n; i++)
        {
            rt.push_back(matrix[x][y]);
            x += dir.first;
            y += dir.second;
            if(x < 0 || y < 0 || x >= m || y >= n)
            {
                // change direction
                dir.first = -dir.first;
                dir.second = -dir.second;
                if(x >= m)
                {
                    x = m - 1;
                    y += 2;
                }
                if(y >= n)
                {
                    y = n - 1;
                    x += 2;
                }
                if(x < 0)
                {
                    x = 0;
                }
                if(y < 0)
                {
                    y = 0;
                }
            }
        }
        return rt;
    }
};
