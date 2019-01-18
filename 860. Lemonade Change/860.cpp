class Solution {
public:
    bool lemonadeChange(vector<int> bills) {
        int five = 0, ten = 0;
        for (int i : bills) {
            if (i == 5) five++;                         // 5
            else if (i == 10) five--, ten++;            // 10
            else if (ten > 0) ten--, five--;            // 20, try change 10 first
            else five -= 3;                             // 20
            if (five < 0) return false;
        }
        return true;
    }
};
