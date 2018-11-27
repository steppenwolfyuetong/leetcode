class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int dis = 0;
        for(int i = 0; i < 32; i++)
        {
            int count = 0;              // 计算第i个bit的为1的个数
            for(auto& num : nums)
            {
                count += (num >> i) & 1;
            }
            dis += count * (nums.size() - count);       // 有count个为1，(n - count)个为0，在这一bit的汉明距离为count * (n - count)
        }
        return dis;
    }
};
