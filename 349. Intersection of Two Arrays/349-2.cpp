#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set(nums1.begin(), nums1.end());
        vector<int> rt;
        for(auto num : nums2)
        {
            if(set.find(num) != set.end())
            {
                rt.push_back(num);
                set.erase(num);
            }
        }
        return rt;
    }
};

int main()
{
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(2);
    a.push_back(1);

    vector<int> b;
    b.push_back(2);
    b.push_back(2);

    Solution s;
    vector<int> rt = s.intersection(a,b);
    for(int i = 0; i < rt.size(); i++)
        cout << rt[i] << endl;
    return 0;
}
