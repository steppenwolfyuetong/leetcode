#include<vector>
#include<iostream>
using namespace std;

// The DP solution proceeds row by row, starting from the first row. 
// Let the maximal rectangle area at row i and column j be computed by 
// [right(i,j) - left(i,j)]*height(i,j).
// left(i,j)��ʾmatrix[i][j] ��i�е�[j]��Ԫ�����ھ�������߽磬ȡ������һ�кͱ��е����߽�
// right(i,j)						  				   �Ҳ�߽�						 ��
// height(i,j)						  				   �߶�



class Solution {
public:
    int maximalRectangle(vector< vector<char> >& matrix) {
        if(matrix.empty())
			return 0;
		const int m = matrix.size();
		const int n = matrix[0].size();
		vector<int> left(n,0),right(n,n-1),height(n,0);
		int ans = 0;
		for(int i = 0; i < m; i++)
		{
			//�����ǰԪ��Ϊ1 curLeft�����i��ȫΪ1�ľ������߽�
			//�����ǰԪ��Ϊ1 curRight�����i��ȫΪ1�ľ����Ҳ�߽�
			//�����ǰԪ��Ϊ0 curLeftΪ0
			//�����ǰԪ��Ϊ1 curRightΪn-1
			int curLeft = 0, curRight = n - 1;
			for(int j = 0; j < n; j++)
			{
				if(matrix[i][j] == '1')
				{
					height[j]++;
					left[j] = max(left[j],curLeft);
				}
				else
				{
					left[j] = 0;
					height[j] = 0;
					curLeft = j + 1;
				}
			}
			
			for(int j = n - 1; j > -1; j--)
			{
				if(matrix[i][j] == '1')
				{			
					right[j] = min(right[j],curRight);
				}
				else
				{
					right[j] = n - 1;
					curRight = j - 1;
				}
			}
			
			for(int j = 0; j < n; j++)
				ans = max(ans,(right[j] - left[j] + 1) * height[j]);
			
			/*
			for(int j = 0; j < n; j++)
				cout<<left[j]<<' ';
			cout<<endl;
			for(int j = 0; j < n; j++)
				cout<<right[j]<<' ';
			cout<<endl;
			for(int j = 0; j < n; j++)
				cout<<height[j]<<' ';
			cout<<endl<<endl;
			*/
		}
		return ans;
		
    }
};

int main()
{
	vector< vector<char> > mat;
	
	vector<char> row0(1,'1');
	mat.push_back(row0);
	/*
	vector<char> row0(7,'0');
	vector<char> row1(7,'0');
	vector<char> row2(7,'0');
	row0[3] = '1';
	row1[2] = row1[3] = row1[4] = '1';
	row2[1] = row2[2] = row2[3] = row2[4] = row2[5] = '1';
	mat.push_back(row0);
	mat.push_back(row1);
	mat.push_back(row2);
	*/

	
	Solution *s = new Solution;
	cout<<s->maximalRectangle(mat)<<endl;
}
