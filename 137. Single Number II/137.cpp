#include<iostream>
#include<memory>
using namespace std;

// 除了一个元素 其余元素有且仅出现3次
// count[i] 表示整个数组中的数在第i个bit出现的1的次数
// 如果count[i]是3的整数倍，说明该位为0，否则为1。



int singleNumber(int* nums, int numsSize) {
	// 求出int的字节数 每一个字节由8个bit组成 共len个bit
	int len = sizeof(int) * 8;
	int count[len];
	for(int i = 0; i < len; i++)
		count[i] = 0;
    for(int i = 0; i < numsSize; i++)
	{
		for(int j = 0; j < len; j++)
			count[j] += (nums[i] >> j) & 1;
	}
	int ans = 0;
	for(int j = 0; j < len; j++)
	{
		if(count[j] % 3)
			ans |= (count[j]%3)<<j;
	}
	return ans;
}

int main()
{
	int num[] = {1,2,3,4,5,6,6,5,4,3,2,1,1,2,3,4,5,6,7};
	cout<<singleNumber(num,19);
}
