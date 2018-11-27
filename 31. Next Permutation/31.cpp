#include<iostream>
using namespace std;


void swap(int *a,int *b)
{
	int t;
	t = *a;*a = *b;*b = t;
	return;
} 

void reverse(int* num,int start,int end)
{
	if(start == end)
		return;
	while(start < end)
	{
		swap(&num[start++],&num[end--]);
	}
	return;
}

void nextPermutation(int* nums, int numsSize) {
	if(numsSize <= 1)
		return;
	int i = 0;
	for(i = numsSize - 1;i > 0;i--)
	{
		if(nums[i] <= nums[i-1])
			continue;
		else
		{
			for(int j = numsSize - 1;j > i-1;j--)
			{
				if(nums[j] > nums[i-1])
				{
					swap(&nums[j],&nums[i-1]);
					break;
				}
			}
			reverse(nums,i,numsSize-1);
			break;
		}
	}
	if(i == 0)
		reverse(nums,0,numsSize-1);
	return;
}


int main()
{
	int x=1,y=2;
	swap(&x,&y);
	cout<<x<<' '<<y<<endl;
	int a[3]={5,1,1};
	nextPermutation(a,3);
	cout<<a[0]<<a[1]<<a[2]<<endl;;
	return 0;
}
