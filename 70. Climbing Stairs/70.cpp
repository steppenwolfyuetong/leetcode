#include<iostream>
#include<malloc.h>
using namespace std;

int climbStairs(int n) {
    if(n == 0 || n == 1)
		return 1;
	int *num = (int*) malloc((n+1) * sizeof(int));
	num[0] = 1;
	num[1] = 1;
	for(int i = 2;i <= n;i++)
	{
		num[i] = num[i-1] + num[i-2];
	}
	return num[n];
}

int main()
{
	cout<<climbStairs(4)<<endl;
}
