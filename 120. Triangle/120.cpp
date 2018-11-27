#include<iostream>
using namespace std;

// ��״̬Ϊ triangle(i,j),��ʾ�Ӵ�λ�� (i, j) ����·������С��
// ��״̬ת�Ʒ���Ϊtriangle(i,j) = triangle(i,j) + min(triangle(i+1,j),triangle(i+1,j+1))

int minimumTotal(int **triangle, int numRows) {
	for(int i = numRows - 2; i >= 0; i--)
		for(int j = 0; j <= i; j++)
			triangle[i][j] += triangle[i+1][j] < triangle[i+1][j+1] ? triangle[i+1][j] : triangle[i+1][j+1];
	return triangle[0][0];
}

int main()
{
	int a[] = {2};
	int b[] = {3,4};
	int c[] = {6,5,7};
	int d[] = {4,1,8,3};
	int *mat[] = {a,b,c,d};
	cout<<minimumTotal(mat,4);
}
