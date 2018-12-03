/*
 *  1/2 1/3 [1/5]
 *  2/3 [2/5]
 *  [3/5]
 *
 *  store the fraction of A[i]/A[j] in priority_queue
 *  [...] is put into pq first, then begin compare
 */

#include <queue>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        // pair<int, int> -> <numerator idx, denominator idx>
        // smaller fraction with higher priority
        auto cmp = [&](const pair<int, int>& p1, const pair<int, int>& p2) {
            return A[p1.first] * A[p2.second] > A[p1.second] * A[p2.first];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        
        int n = A.size();
        for (int i = 0; i < n - 1; i++) {
            pq.push(make_pair(i, n - 1));
        }

        int count = 0;
        while (count < K - 1) {
            pair<int, int> cur = pq.top();
            pq.pop();
            count++;
            if (cur.first < cur.second - 1) {
                pq.push(make_pair(cur.first, cur.second - 1));
            }
        }
        return vector<int> {A[pq.top().first], A[pq.top().second]};
    }
};

int main() {
    Solution *s = new Solution();
    vector<int> A{1,2,3,5};
    s->kthSmallestPrimeFraction(A, 3);
    return 0;
}
