#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, compare> pq;
        for(int i = 0; i < matrix.size(); i++)
        {
            pq.push(make_pair(matrix[i][0], make_pair(i,0)));
        }

        int count = k, rt;
        while(count--)
        {
            pair<int,pair<int,int>> ele = pq.top();
            int val = ele.first, x = ele.second.first, y = ele.second.second;
            rt = val;
            pq.pop();
            if(y != matrix[0].size() - 1)
            {
                pq.push(make_pair(matrix[x][y+1],make_pair(x,y+1)));
            }
        }
        return rt;
    }

	struct compare
	{
		bool operator()(const pair<int,pair<int,int>> a, const pair<int,pair<int,int>> b)
	    {
	        return a.first > b.first;
	    }
	};

};

int main()
{
    Solution *s;
    vector<vector<int>> matrix;
    matrix.resize(3);
    int ele[3][3] = {{1,  5,  9}, {10, 11, 13}, {12, 13, 15}};
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            matrix[i].push_back(ele[i][j]);
        }
    }
    
    cout << s->kthSmallest(matrix, 8) << endl;
    return 0;
}
