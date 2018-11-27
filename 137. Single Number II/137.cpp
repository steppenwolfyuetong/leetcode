#include<iostream>
#include<memory>
using namespace std;

// ����һ��Ԫ�� ����Ԫ�����ҽ�����3��
// count[i] ��ʾ���������е����ڵ�i��bit���ֵ�1�Ĵ���
// ���count[i]��3����������˵����λΪ0������Ϊ1��



int singleNumber(int* nums, int numsSize) {
	// ���int���ֽ��� ÿһ���ֽ���8��bit��� ��len��bit
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
