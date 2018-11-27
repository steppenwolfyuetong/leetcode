class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> edge;
        for(auto row : wall)
        {
            int sum = 0;
            for(int i = 0; i < row.size() - 1; i++)
            {
                sum += row[i];
                edge[sum]++;
            }
        }

        int rt = 0;
        for(auto kv : edge)
        {
            // cout << kv.first << ' ' << kv.second << endl;
            if(kv.second > rt)
                rt = kv.second;
        }
        return wall.size() - rt;
    }
};
