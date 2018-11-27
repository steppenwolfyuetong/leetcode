class Solution {
public:
    int hammingDistance(int x, int y) {
        int rt = 0, n = x ^ y;
        while(n)
        {
            rt++;
            n &= n - 1;
        }
        return rt;
    }
};
