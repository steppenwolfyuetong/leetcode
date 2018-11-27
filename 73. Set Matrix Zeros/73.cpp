#include<vector>
#include<malloc.h>
#include<iostream>
using namespace std;
// 复用第一行和第一列
// 常数空间

class Solution {
public:
    void setZeroes(vector< vector<int> >& matrix) {
		int m = matrix.size();
		int n = matrix[0].size();
		bool rowIsZero = false;
		bool colIsZero = false;
		
		for(int i = 0; i < m; i++)
			if(matrix[i][0] == 0)
			{
				colIsZero = true;
				break;
			}
		for(int j = 0; j < n; j++)
			if(matrix[0][j] == 0)
			{
				rowIsZero = true;
			}
		
		for(int i = 1; i < m; i++)
			for(int j = 1; j < n; j++)
			{
				if(matrix[i][j] == 0)
				{
					matrix[0][j] = 0;
					matrix[i][0] = 0;
				}
			}

		for(int i = 1; i < m; i++)
			for(int j = 1; j < n; j++)
				if(matrix[i][0] == 0 || matrix[0][j] == 0)
					matrix[i][j] = 0;
		
		if(colIsZero)
			for(int i = 0; i < m; i++)
				matrix[i][0] = 0;
		
		if(rowIsZero)
			for(int j = 0; j < n; j++)
				matrix[0][j] = 0;
    }
};

int main()
{
	vector<int> a,b(5,2),c(5,3),d(5,4),e(5,5);
	a.push_back(1);
	a.push_back(0);
	a.push_back(1);
	a.push_back(1);
	a.push_back(1);
	vector< vector<int> > mat;
	mat.push_back(a);
	mat.push_back(b);
	mat.push_back(c);
	mat.push_back(d);
	mat.push_back(e);
	
	Solution *s = new Solution;
	s->setZeroes(mat);
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
			cout<<mat[i][j]<<' ';
		cout<<endl;
	}
	return 0;
}

