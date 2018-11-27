#include<iostream>
using namespace std;

// 异或运算 偶数次均可解决
// a ^ a = 0
// a ^ b ^ a = b
// 依次异或下一个数，因而出现偶数次的均被消除

int singleNumber(int* nums, int numsSize) {
	int ans = nums[0];
    for(int i = 1; i < numsSize; i++)
	{
		ans ^= nums[i];
	}
	return ans;
}

int main()
{
	int num[] = {1,2,3,4,5,6,7,6,5,4,3,2,1};
	cout<<singleNumber(num,13);
}

