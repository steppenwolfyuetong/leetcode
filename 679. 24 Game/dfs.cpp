#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> vec(nums.begin(), nums.end());        
        return dfs(vec);
    }

    bool dfs(vector<double> nums) {
        if (nums.size() == 1) {
            if (abs(nums.front() - 24.0) < eps) {
                return true;
            }
            return false;
        }

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                double n1 = nums[i], n2 = nums[j];
                vector<double> next;
                for (int k = 0; k < nums.size(); k++) {
                    if (k != i && k != j) {
                        next.push_back(nums[k]);
                    }
                }

                for (auto cal : calculate(n1, n2)) {
                    next.push_back(cal);
                    if (dfs(next))
                        return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }

    vector<double> calculate(double n1, double n2) {
        vector<double> cal{n1 + n2, n1 - n2, n2 - n1, n1 * n2};
        if (abs(n1) > eps) {
            cal.push_back(n2 / n1);
        }
        if (abs(n2) > eps) {
            cal.push_back(n1 / n2);
        }
        return cal;
    }

    double eps = 1e-5;
};

int main() {
    //vector<int> nums{4,1,8,7};
    vector<int> nums{1,2,1,3};
    Solution *s = new Solution();
    cout << s->judgePoint24(nums) << endl;
    return 0;
}
