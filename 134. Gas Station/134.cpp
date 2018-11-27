#include<iostream>
using namespace std;

// Note: The solution is guaranteed to be unique.
// 存在唯一解 要么存在某个起点能环绕一圈 要么就不存在解
// 如果所有站的代价和大于0，则所求的路线必定存在。
// 如果总代价>=0,从序号0开始求代价和，
// 如果代价和小于0，则不是从本站或者本站之前的某一个代价大于0的站开始，
// 必从下一站即之后的站开始

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int total = 0;
	int index = 0;
	for(int i = 0, cur = 0; i < gasSize; i++)
	{
		// cur判断以index为起点是否能环绕
		cur += gas[i] - cost[i];
		// total判断整个数组是否有解
		total += gas[i] - cost[i];
		
		if(cur < 0)
		{
			index = (i+1) % gasSize;
			cur = 0;
		}
	}
	if(total < 0)
		return -1;
	else
		return index;
}

int main()
{
	int gas[] = {1,1,1,1,1,1};
	int cost[] = {1,1,1,1,1,1};
	cout<<canCompleteCircuit(gas,6,cost,6)<<endl;
}
