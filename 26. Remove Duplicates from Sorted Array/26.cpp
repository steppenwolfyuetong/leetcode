// Do not allocate extra space for another array, you must do this in place with constant memory.
// 空间复杂度必须为O(1)
#include<stdio.h>

int removeDuplicates(int* nums, int numsSize) {
	// index存储下一个可填写的位置 index之前的所有数均不重复
	if (numsSize == 0)
		return 0;
	int index = 1;
	for(int i = 0; i < numsSize; i++)
	{
		if (nums[index-1] != nums[i])
			nums[index++] = nums[i];
	}
	return index;
}

int main()
{
	int a[2]={};
	printf("%d",removeDuplicates(a,2));
}
