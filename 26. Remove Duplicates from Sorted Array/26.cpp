// Do not allocate extra space for another array, you must do this in place with constant memory.
// �ռ临�Ӷȱ���ΪO(1)
#include<stdio.h>

int removeDuplicates(int* nums, int numsSize) {
	// index�洢��һ������д��λ�� index֮ǰ�������������ظ�
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
