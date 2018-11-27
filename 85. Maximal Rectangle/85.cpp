#include<vector>
#include<iostream>
using namespace std;

// The DP solution proceeds row by row, starting from the first row. 
// Let the maximal rectangle area at row i and column j be computed by 
// [right(i,j) - left(i,j)]*height(i,j).
// left(i,j)表示matrix[i][j] 第i行第[j]列元素所在矩阵的左侧边界，取决于上一行和本行的左侧边界
// right(i,j)						  				   右侧边界						 右
// height(i,j)						  				   高度



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
			//如果当前元素为1 curLeft保存第i行全为1的矩形左侧边界
			//如果当前元素为1 curRight保存第i行全为1的矩形右侧边界
			//如果当前元素为0 curLeft为0
			//如果当前元素为1 curRight为n-1
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
