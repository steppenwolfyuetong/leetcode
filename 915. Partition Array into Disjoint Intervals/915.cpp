#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int n = A.size();
        vector<int> B(n, 0);                    // B[i] is the min in subarray A[i:]
        B.back() = A.back();
        for (int i = A.size() - 2; i > -1; i--) {
            B[i] = min(A[i], B[i + 1]);
        }

        for (const auto& x : B) {
            cout << x << " ";
        }
        cout << endl;

        // curMax is the max element from left to right
        // the result would be the first i which satisfies curMax <= B[i]
        int curMax = INT_MIN;

        // left and right are non-empty
        for (int i = 0; i < n - 1; i++) {
            curMax = max(curMax, A[i]);
            if (curMax <= B[i + 1]) {           // compare left and right
                return i + 1;                   // return length
            }
        }
        return -1;
    }
};

// one pass, hard to understand
/*
 *  public int partitionDisjoint(int[] a) {
        int localMax = a[0], partitionIdx = 0, max = localMax;
        for (int i = 1; i < a.length; i++)
            if (localMax > a[i]) {
                localMax = max;
                partitionIdx = i;
            } else {
                max = Math.max(max, a[i]);
            }
        return partitionIdx + 1;
    }
 */

int main() {
    Solution s;
    vector<int> A = {5,0,3,8,6};
    cout << s.partitionDisjoint(A) << endl;
}
