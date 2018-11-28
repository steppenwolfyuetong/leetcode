class Solution {
public:
    double soupServings(int N) {
        return dfs(N, N);    
    }

    double dfs(int A, int B) {
        if (A == 0 && B != 0)
            return 1;
        if (A == 0 && B == 0)
            return 0.5;
        if (A != 0 && B == 0)
            return 0;

        if (cache[A][B] != 0) {
            return cache[A][B];
        }

        double result = 0;
        result += 0.25 * dfs(A - min(100, A), B);
        result += 0.25 * dfs(A - min(75, A), B - min(25, B));
        result += 0.25 * dfs(A - min(50, A), B - min(50, B));
        result += 0.25 * dfs(A - min(25, A), B - min(75, B));

        cache[A][B] = result;
        return result;
    }
private:
    unordered_map<int, unordered_map<int, double>> cache;
};
