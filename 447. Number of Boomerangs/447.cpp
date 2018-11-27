class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int rt = 0;
        for(int i = 0; i < points.size(); i++)
        {
            unordered_map<int, int> table(points.size());
            for(int j = 0; j < points.size(); j++)
            {
                if(i == j)
                    continue;

                int dis = distance(points[i], points[j]);
                table[dis]++;
            }

            for(auto p : table)
            {
                int count = p.second;
                {
                    rt += count * (count - 1);
                }
            }
        }
        return rt;
    }

    int distance(pair<int, int> &a, pair<int, int> &b)
    {
        int x = a.first - b.first;
        int y = a.second - b.second;
        return x * x + y * y;
    }
};

int main()
{
}
