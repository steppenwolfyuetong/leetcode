#include<iostream>
using namespace std;

int trap(int* height, int heightSize) {
	int result = 0, count = 0, lastBar = 0, index = 0, maxHeight = 0;
	
	// ÕÒµ½×î¸ß
	for(int i = 0; i < heightSize;i++)
	{
		if(height[i] > maxHeight)
		{
			maxHeight = height[i];
			index = i;
		}
	}
	
	// ´Ó×óÍùÓÒÉ¨Ãè
    for(int i = 0; i <= index; i++)
	{
		if(lastBar == 0)
		{
			if(height[i] != 0)
			{
				lastBar = height[i];
			}
		}
		else
		{
			if(height[i] < lastBar)
				count += lastBar - height[i];
			else
			{
				result += count;
				count = 0;
				lastBar = height[i];
			}
		}
		//cout<<"i = "<<i<<" height = "<<height[i]<<" lastBar = "<<lastBar<<" count = "<<count<<" result = "<<result<<endl;
	}	
	//´ÓÓÒÍù×óÉ¨Ãè
	count = 0;
	lastBar = 0;
	for(int i = heightSize - 1; i >= index; i--)
	{
		if(lastBar == 0)
		{
			if(height[i] != 0)
			{
				lastBar = height[i];
			}
		}
		else
		{
			if(height[i] < lastBar)
				count += lastBar - height[i];
			else
			{
				result += count;
				count = 0;
				lastBar = height[i];
			}
		}
		//cout<<"i = "<<i<<" height = "<<height[i]<<" lastBar = "<<lastBar<<" count = "<<count<<" result = "<<result<<endl;
	}
	return result;
}

int main()
{
//	int a[12] = {0,1,0,2,1,0,1,3,2,1,2,1};
//	cout<<trap(a,12)<<endl;
	int a[3] = {2,0,2};
	cout<<trap(a,3)<<endl;
}
