#include<iostream>
using namespace std;

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int m;
	m = (nums1Size + nums2Size) / 2 + 1;
	int p1 = 0, p2 = 0, n = 0;
	int a = 0, b = 0;									// a,b分别保存当前序列最大数和次大数 n为当前序列数字个数
	while(n < m)
	{
		if(p1 == nums1Size)
		{
			b = a; a = nums2[p2++]; n++; continue;
		}
		if(p2 == nums2Size) 
		{
			b = a; a = nums1[p1++]; n++; continue;
		}
		if(nums1[p1] < nums2[p2]) 
		{
			b = a; a = nums1[p1++]; n++; continue;
		}
		else
		{
			b = a; a = nums2[p2++]; n++; continue;
		}
	}
	//cout << a << b << endl;
	if((nums1Size + nums2Size) % 2 != 0)
		return a;
	else
	{
		return ((float)a + (float)b) / 2;
	}
}

int main()
{
	int a[1]={2};
	int b[]={};
	cout<<findMedianSortedArrays(a,1,b,0);
}
