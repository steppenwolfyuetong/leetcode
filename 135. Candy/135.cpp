#include<iostream>
using namespace std;

// 根据题意
// 相邻的相等rating 后一个可以只给1个糖果
/*
基本思路就是进行两次扫描，一次从左往右，一次从右往左。
第一次扫描的时候维护对于每一个小孩左边所需要最少的糖果数量（寻找递增），存入数组对应元素中;
第二次扫描的时候维护右边所需的最少糖果数（寻找递减），并且比较将左边和右边大的糖果数量存入结果数组对应元素中。
这样两遍扫描之后就可以得到每一个所需要的最最少糖果量，从而累加得出结果。
*/


int candy(int* ratings, int ratingsSize) {
	if(ratingsSize == 0)
		return 0;
	int result[ratingsSize];
	for(int i = 0; i < ratingsSize; i++)
		result[i] = 1;
	int ans = 0;
	for(int i = 1; i < ratingsSize; i++)
	{
		if(ratings[i] > ratings[i-1])
		{
			result[i] = result[i-1] + 1;
		}
	}
	for(int i = ratingsSize - 1; i > 0; i--)
	{
		if(ratings[i] < ratings[i-1])
		{
			result[i-1] = result[i] + 1 > result[i-1] ? result[i] + 1 : result[i-1];
		}
	}
	
	for(int i = 0; i < ratingsSize; i++)
		ans += result[i];
	return ans;
	
}

int main()
{
	int rate[13] = {1,2,5,8,4,3,3,5,7,9,2,1,1};
	cout<<candy(rate,13)<<endl;;
}

