class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> table;
        for(auto& numC : C)
        {
            for(auto& numD : D)
            {
                table[numC + numD]++;
            }
        }

        int rt = 0;
        for(auto& numA : A)
        {
            for(auto& numB : B)
            {
                unordered_map<int, int>::iterator iter = table.find(-(numA + numB));
                if(iter != table.end())
                    rt += iter->second;
            }
        }
        return rt;
    }
};
