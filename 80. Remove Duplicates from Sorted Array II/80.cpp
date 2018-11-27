#include<stdio.h>

int removeDuplicates(int* nums, int numsSize) {
	if (numsSize == 0)
		return 0;
	int index = 1,count = 1;
	for(int i = 1; i < numsSize; i++)
	{
		//printf("index = %d i = %d count = %d\n",index,i,count);
		if (nums[index-1] == nums[i])
		{	
			if(count == 1)
			{
				nums[index++] = nums[i];
				count++;
			}
		}	
		else
		{
			nums[index++] = nums[i];
			count = 1;
		}
	}
	return index;
}

int main()
{
	int a[6]={1,1,1,2,2,3};
	printf("%d",removeDuplicates(a,6));
}
