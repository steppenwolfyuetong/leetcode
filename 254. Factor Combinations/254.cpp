/*
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void getResult(vector<vector<int>> &result,vector<int> &row,int n){
        int i = row.empty() ? 2 : row.back();
        for(; i <= n / i; ++i){
            if(n % i == 0)
            {
                row.push_back(i);
                row.push_back(n/i);
                result.push_back(row);
                row.pop_back();
                getResult(result, row , n / i);
                row.pop_back();
            }
        }
    }

    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> result;
        vector<int>row;
        getResult(result,row,n);
        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<int> > rt = s.getFactors(32);
    for(int i = 0; i < rt.size(); i++)
    {
        for(int j = 0; j < rt[i].size(); j++)
        {
            cout << rt[i][j] << ' ';
        }
        cout << endl;
    }
}
