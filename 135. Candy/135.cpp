#include<iostream>
using namespace std;

// ��������
// ���ڵ����rating ��һ������ֻ��1���ǹ�
/*
����˼·���ǽ�������ɨ�裬һ�δ������ң�һ�δ�������
��һ��ɨ���ʱ��ά������ÿһ��С���������Ҫ���ٵ��ǹ�������Ѱ�ҵ����������������ӦԪ����;
�ڶ���ɨ���ʱ��ά���ұ�����������ǹ�����Ѱ�ҵݼ��������ұȽϽ���ߺ��ұߴ���ǹ����������������ӦԪ���С�
��������ɨ��֮��Ϳ��Եõ�ÿһ������Ҫ���������ǹ������Ӷ��ۼӵó������
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

