#include<iostream>
#include<malloc.h>
using namespace std;

bool check(char x,bool flag[])
{
	if(x == '.')
		return true;
	if(flag[x - '1'])
		return false;
	else
	{
		flag[x - '1'] = true;
		return true;
	}
}

bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    bool rowUsed[9],colUsed[9],used[9];
	memset(rowUsed,false,9);
	memset(colUsed,false,9);
	memset(used,false,9);
	for(int i = 0;i < boardRowSize;i++)
	{
		memset(rowUsed,false,9);
		memset(colUsed,false,9);
		for(int j = 0; j < boardColSize; j++)
		{
			//�����
			if(check(board[i][j],rowUsed) == false)
				return false;
			//�����
			if(check(board[j][i],colUsed) == false)
				return false;
		}
	}
	for(int i = 0;i < 3;i++)
		for(int j = 0; j < 3; j++)
		{
			memset(used,false,9);
			for(int m = 0; m < 3; m++)
				for(int n = 0; n < 3; n++)
					if(check(board[3*i+m][3*j+n],used) == false)
						return false;
		}
	return true;
}



/*
����ָ�뱣�����һ��ָ��ĵ�ַ ����������ָ�����
��һ��ָ�뱣�����ָ���������ڵ��ڴ浥Ԫ�ĵ�ַ
��Ȼ���ǵ�ַ�����������ǲ�һ����
*/



int main()
{
	
//	char **board = new char*[9];
	char **board = (char **) malloc(9 * sizeof(char*));
	board[0] = "53..7....";
	board[1] = "6..195...";
	board[2] = ".98....6.";
	board[3] = "8...6...3";
	board[4] = "4..8.3..1";
	board[5] = "7...2...6";
	board[6] = ".6....28.";
	board[7] = "...419..5";
	board[8] = "....8..79";

	cout<<isValidSudoku(board,9,9)<<endl;
}
