class Solution {
public:
    vector<vector<int>> rectangles;
    vector<int> areas;
    int total;


    Solution(vector<vector<int>> rects) {
        rectangles = rects;
        total = 0;
        areas.push_back(0);
        for (auto& rect : rects) {
            // We add 1 because we can choose values on the border.
            total += (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
            areas.push_back(total);
        }

    }
    
    vector<int> pick() {
        vector<int> result;
        int value = rand() % total;
        int index = upper_bound(areas.begin(), areas.end(), value) - areas.begin() - 1; 
        int width = rectangles[index][2] - rectangles[index][0] + 1;
        int height = rectangles[index][3] - rectangles[index][1] + 1;
        return {
            rand() % width + rectangles[index][0],
            rand() % height + rectangles[index][1]
        };
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(rects);
 * vector<int> param_1 = obj.pick();
 */

