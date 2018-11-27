#include <limits.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if(points.empty())
            return 0;

        sort(points.begin(), points.end(), pointCmp);
        // curMinValidEnd保存当前能一箭同时命中的气球中 结束坐标最小的一个
        int count = 1, curMinValidEnd = points.front().second;
        for(int i = 1; i < points.size(); i++)
        {
            pair<int, int> balloon = points[i];
            // 当前的气球 不能和 之前的可以同时一箭命中的气球同时命中 需要再用新的一箭
            if(balloon.first > curMinValidEnd)
            {
                curMinValidEnd = balloon.second;
                count++;
            }
            // 保存curMinValidEnd
            else
            {
                curMinValidEnd = min(curMinValidEnd, balloon.second);
            }
        }
        return count;
    }
private:
    static bool pointCmp(pair<int, int> &a, pair<int, int> &b)
    {
        if(a.first != b.first)
            return a.first < b.first;
        else
            return a.second < b.second;
    }
};

int main()
{
	Solution *s = new Solution();
    vector<pair<int, int>> points;
    
    points.push_back(pair<int, int>(10,16));
    points.push_back(pair<int, int>(2,8));
    points.push_back(pair<int, int>(1,6));
    points.push_back(pair<int, int>(7,12));
    
    cout << s->findMinArrowShots(points) << endl;
    points.clear();

    points.push_back(pair<int, int>(1,2));
    points.push_back(pair<int, int>(3,4));
    points.push_back(pair<int, int>(5,6));
    points.push_back(pair<int, int>(7,8));


    cout << s->findMinArrowShots(points) << endl;
    return 0;
}
