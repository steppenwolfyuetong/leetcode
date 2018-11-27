class Solution {
public:
    // [1,2], [1,2,3]
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int indexG = 0, indexS = 0;
        while(indexG < g.size() && indexS < s.size())
        {
            if(g[indexG] <= s[indexS])
            {
                indexG++;
                indexS++;
            }
            else
            {
                indexS++;
            }
        }
        return indexG;
    }
};
