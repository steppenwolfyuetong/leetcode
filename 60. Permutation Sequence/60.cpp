#include<iostream>
#include<malloc.h>
using namespace std;

/*
����չ������
����չ���Ĺ�ʽ�� X=an*(n-1)!+an-1*(n-2)!+...+ai*(i-1)!+...+a2*1!+a1*0! 
���У�aiΪ��ǰδ���ֵ�Ԫ���������ڵڼ�������0��ʼ �ܹؼ�����
����֪ĳһ���У���X��Ҳ������an...a1������

������Ϊ����չ����������
����֪X����������

����ĳһ������ ��X-1�����б���С ʵ�ʾ�����X-1��չ�� 
������ʼ�
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
		// ��num�� δʹ�ù��ĵ�j��Ԫ�� �ӵ�0��ʼ
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
