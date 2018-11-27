#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    // TLE...
    // Java AC
    /*
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());

        int minRadius = 0;
        for(auto house : houses)
        {
            // 找到第一个坐标大于等于house的heater
            // 对于每一个house落在(smallerHeater, largerHeater)区间内
            // 比较house到区间两端的最小长度为curRadius
            // 再更新全局变量minRadius
            vector<int>::iterator largerHeater = lower_bound(heaters.begin(), heaters.end(), house);
            vector<int>::iterator smallerHeater;
            int curRadius = INT_MAX;

            if(largerHeater != heaters.end())
            {
                curRadius = (*largerHeater) - house;
            }

            if(largerHeater != heaters.begin())
            {
                smallerHeater = largerHeater - 1;
                curRadius = min(curRadius, house - (*smallerHeater));
            }
            minRadius = max(curRadius, minRadius);
        }
        return minRadius;
    }
    */

    // 双指针
    // Based on 2 pointers, the idea is to find the nearest heater for each house, by comparing the next heater with the current heater.
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int index = 0, minRadius = 0;
        for(int i = 0; i < houses.size(); i++)
        {
            while(index + 1 < heaters.size() &&
                    abs(heaters[index + 1] - houses[i]) <= abs(heaters[index] - houses[i]))
            {
                index++;
            }
            minRadius = max(minRadius, abs(heaters[index] - houses[i]));
        }
        return minRadius;
    }
};

int main()
{
    int houseArray[] = {1,2,3,4};
    vector<int> houses(houseArray, houseArray + sizeof(houseArray) / sizeof(int));
    int heaterArray[] = {1,4};
    vector<int> heaters(heaterArray, heaterArray + sizeof(heaterArray) / sizeof(int));

    Solution *s = new Solution();
    cout << s->findRadius(houses, heaters);
    return 0;
}
