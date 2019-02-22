class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (const auto& prime : primes) {
            pq.push(prime);
        }

        int count = 1;                  // 1 is also the super ugly numbers
        int ugly = 1;
        while (count < n) {
            ugly = pq.top();
            pq.pop();
            count++;

            for (const auto& prime : primes) {
                long candidate = static_cast<long>(prime) * static_cast<long>(ugly);
                if (candidate < INT_MAX) {
                    pq.push(candidate);
                }
            }

            // need to pop out same result
            while (pq.top() == ugly) {
                pq.pop();
            }
        }
        return ugly;
    }
};
