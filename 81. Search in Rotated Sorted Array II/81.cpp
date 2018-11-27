int binary(int* num, int start, int end, int tar)
{
	
	int mid = (start + end) / 2;
	if (num[mid] == tar)
		return true;
	if (start >= end)
		return false;
	if (tar > num[mid])
		return binary(num,mid+1,end,tar);
	else
		return binary(num,start,mid,tar);
}

int search(int* nums, int numsSize, int target) {
	int i;
	for(i = 1;i < numsSize;i++)
	{
		if (nums[i] < nums[i-1])
			break;
	}
	if (i<numsSize)
	{
		if (target >= nums[i] && target <= nums[numsSize-1])
			return binary(nums,i,numsSize-1,target);
		else
			return binary(nums,0,i-1,target);
	}
	else
		// 还有没有反转的情况
		return binary(nums,0,numsSize-1,target);
}
