#include<iostream>
using namespace std;

// Note: The solution is guaranteed to be unique.
// ����Ψһ�� Ҫô����ĳ������ܻ���һȦ Ҫô�Ͳ����ڽ�
// �������վ�Ĵ��ۺʹ���0���������·�߱ض����ڡ�
// ����ܴ���>=0,�����0��ʼ����ۺͣ�
// ������ۺ�С��0�����Ǵӱ�վ���߱�վ֮ǰ��ĳһ�����۴���0��վ��ʼ��
// �ش���һվ��֮���վ��ʼ

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int total = 0;
	int index = 0;
	for(int i = 0, cur = 0; i < gasSize; i++)
	{
		// cur�ж���indexΪ����Ƿ��ܻ���
		cur += gas[i] - cost[i];
		// total�ж����������Ƿ��н�
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
