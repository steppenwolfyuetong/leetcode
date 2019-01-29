#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int round = minutesToTest / minutesToDie;
        return ceil(log(buckets) / log(round + 1));
    }
};

int main()
{
	Solution *s = new Solution();
	cout << s->poorPigs(1000, 15, 60) << endl;
	return 0;
}
/*
 * (8 buckets, 1 minutesToDie, 1 minutesToTest)
 *  0   1   2   3   4   5   6   7
 *  000 001 010 011 100 101 110 111 
 *
 *  有1轮
 *  3只即可 3个bit分别代表3只猪 
 *  某一位为0即代表对应的猪没有喝该桶
 *  某一位为1即代表对应的猪在第1轮喝了该桶
 *
 *  也就是第一个猪喝最低位为1的 第二个猪喝次低位为1的 第三个猪喝最高位为1的
 *
 *********************************************************************
 *
 * (8 buckets, 1 minutesToDie, 2 minutesToTest)
 *  0   1   2   3   4   5   6   7
 *  00  01  02  10  11  12  20  21      (3-based) 
 *
 *  有两轮
 *  2只即可
 *  某一位为0即代表对应的猪没有喝该桶
 *  某一位为1即代表对应的猪在第1轮喝了该桶
 *  某一位为2即代表对应的猪在第2轮喝了该桶
 *********************************************************************
 *
 * (m buckets, n minutesToDie, p minutesToTest)
 * 轮数为int round = floor(p/n)
 * 需要round + 1进制数来表示m个数
 * 因此至少需要ceil(log(m, round + 1))只猪
 */
