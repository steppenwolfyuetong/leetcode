class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        v = vec2d;
        x = y = 0;
    }
    int next() {
        return v[x][y++];
    }
    bool hasNext() {
        while (x < v.size() && y == v[x].size()) {
            ++x; 
            y = 0;
        }
        return x < v.size();
    }    
private:
    vector<vector<int>> v;
    int x, y;
};
