/*
There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2]is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.

Follow up:
Could you solve it in O(nk) runtime?
*/

/*
和I的思路一样，不过这里我们有K个颜色，不能简单的用min方法了。如果遍历一遍颜色数组就找出除了自身外最小的颜色呢？我们只要把最小和次小的都记录下来就行了，这样如果和最小的是一个颜色，就加上次小的开销，反之，则加上最小的开销。
*/

#include <limits.h>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if(costs.empty() || costs[0].empty()) 
            return 0;
        int preMin1 = 0, preMin2 = 0, preIndex = -1;
        for(int i = 0; i < costs.size(); i++)
        {
            int curMin1 = INT_MAX, curMin2 = INT_MAX, curIndex = -1;
            for(int j = 0; j < costs[i].size(); j++)
            {
                costs[i][j] += (preIndex == j ? preMin2 : preMin1);
                //找到最小的和次小的花费即可 用于下一个房子的花费计算
                if(costs[i][j] < curMin1)
                {
                    curMin2 = curMin1;
                    curMin1 = costs[i][j];
                    curIndex = j;
                }
                else if(costs[i][j] < curMin2)
                {
                    curMin2 = costs[i][j];
                }
            }
            preMin1 = curMin1;
            preMin2 = curMin2;
            preIndex = curIndex;
        }
        return preMin1;
    }
};
