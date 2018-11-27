#include<iostream>
#include<malloc.h>
using namespace std;

/*
康托展开问题
康托展开的公式是 X=an*(n-1)!+an-1*(n-2)!+...+ai*(i-1)!+...+a2*1!+a1*0! 
其中，ai为当前未出现的元素中是排在第几个（从0开始 很关键）。
即已知某一排列，求X，也就是求an...a1的问题

本问题为康托展开的逆运算
即已知X，求其排列

对于某一个排列 有X-1个排列比它小 实际就是求X-1的展开 
具体见笔记
*/

char* getPermutation(int n, int k) {
	int fac[9]={1,1,2,6,24,120,720,5040,40320};
	int num[9]={1,2,3,4,5,6,7,8,9};
	int flag[9]={0};
    int *ans = (int *) malloc(n * sizeof(int));
	int an = 0;
	k = k - 1;
	for(int i = n;i > 0;i--)
	{
		int j = k / fac[i-1];
		// 求num中 未使用过的第j大元素 从第0大开始
		int x = 0,index = 0;
		while(1)
		{
			if(flag[index] == 1)
			{
				index++;
			}
			else
			{
				if(x == j)
					break;
				x++;
				index++;
			}
		}
		flag[index] = 1;
		ans[an++] = num[index];
		k = k % fac[i-1];
	}
	
	char *res = (char *) malloc((n+1) * sizeof(char));
	for(int i = 0;i < n;i++)
		res[i] = ans[i] + '0';
	res[n] = '\0';
	return res;
}

int main()
{
	getPermutation(9,54494);
}
