class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;        
        int sum = 0;
        int result = INT_MAX;

        for (int i = 0; i < A.size(); i++) { 
            sum += A[i];
            if (sum >= K) {
                result = min(result, i + 1);
            }
            while (!pq.empty() && sum - pq.top().first >= K) {
                pair<int, int> p = pq.top();
                pq.pop();
                result = min(result, i - p.second);
            }

            pq.push({sum, i});
        }
        return result == INT_MAX ? -1 : result;
    }
};
