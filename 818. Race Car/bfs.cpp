class Solution {
private:
    struct info {
        int pos = 0;
        int speed = 0;

        info (int pos, int speed) {
            this->pos = pos;
            this->speed = speed;
        }

        string str() {
            return to_string(pos) + "," + to_string(speed);
        }
    };
public:
    int racecar(int target) {
        // pair<int, int> to store the state of a car with (pos, speed)
        info start(0, 1);
        queue<info> q;
        q.push(start);
        unordered_set<string> cache;
        cache.insert(start.str());

        int step = 0;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                int pos = q.front().pos;
                int speed = q.front().speed;
                q.pop();

                if (pos == target) {
                    return step;
                }

                info A(pos + speed, speed * 2);
                info R(pos, speed > 0 ? -1 : 1);

                if (!cache.count(A.str()) && 0 < A.pos && A.pos < target * 2) {
                    q.push(A);
                    cache.insert(A.str());
                }

                if (!cache.count(R.str()) && 0 < R.pos && R.pos < target * 2) {
                    q.push(R);
                    cache.insert(R.str());
                }
            }

            step++;
        }
        return -1;
    }
};
