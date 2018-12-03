#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // invarient: with target is kth smallest element, low <= target <= high, 
        int m = matrix.size(), n = matrix.front().size();

        int low = matrix[0][0], high = matrix[m-1][n-1]; 
        while (low < high - 1) {
            int mid = (low + high) / 2;

            // count elements which are smaller than mid
            int count = 0;
            for (auto& row : matrix) {
                count += lower_bound(row.begin(), row.end(), mid) - row.begin();
            }

            // k is the target
            // count of [low, mid) < k, so the target's range must in [mid, high]
            // count of [low, mid) >= k, so the target's range must in [low, mid)
            //
            // and we need to handle the case when low + 1 = high
            // in that case, it may goto low = mid, and loop forever
            // so while (low < high - 1)
            if (count < k) {
                low = mid;
            } else {
                high = mid -1;
            }
        }

        // handle low = high - 1
        if (low == high - 1) {
            int count = 0;
            for (auto& row : matrix) {
                count += lower_bound(row.begin(), row.end(), high) - row.begin();
            }

            // count is [matrix[0][0], lower]
            if (count >= k) {
                return low;
            } else {
                return high;
            }
        } else {
            return low;
        }
    }
};

int main()
{
    Solution *s;
    vector<vector<int>> matrix;
    matrix.resize(3);
    int ele[3][3] = {{1,  5,  9}, {10, 11, 13}, {12, 13, 15}};
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            matrix[i].push_back(ele[i][j]);
        }
    }
    
    for (int i = 1; i <= 9; i++) {
        cout << s->kthSmallest(matrix, i) << endl;
    }
    return 0;
}
