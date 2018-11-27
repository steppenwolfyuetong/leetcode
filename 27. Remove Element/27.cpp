#include<iostream>
using namespace std;

int removeElement(int* nums, int numsSize, int val) {
	int i = 0,j = 0;
	for(j = 0;j < numsSize;j++)
	{
		if(nums[j] != val)
			nums[i++] = nums[j];
	}
	return i;
}

int main()
{
	int a[4]={1,3,3,4};
	cout<< removeElement(a,4,3) << endl;
	return 0;
}
