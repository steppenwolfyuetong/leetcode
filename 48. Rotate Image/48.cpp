#include<iostream>
#include<malloc.h>
using namespace std;

void swap(int *,int*);
void display(int **,int,int);
void rotate(int**,int ,int);

void swap(int *a,int *b)
{
	int t;
	t = *a;*a = *b;*b = t;
	return;
} 

void display(int** mat, int rowSize, int colSize)
{
	for(int i = 0; i < rowSize; i++)
	{
		for(int j = 0 ; j < colSize ; j++)
			cout<<mat[i][j]<<' ';
		cout<<endl;
	}
	cout<<endl;
	return;
} 

void rotate(int** matrix, int matrixRowSize, int matrixColSize) {
	int row = matrixRowSize % 2 ? matrixRowSize/2 : matrixRowSize/2 - 1;
	for(int i = 0; i <= row; i++)
		for(int j = 0; j < matrixColSize; j++)
			swap(& matrix[i][j],& matrix[matrixRowSize-i-1][j]);
	for(int i = 0; i < matrixRowSize; i++)
		for(int j = 0; j <= i; j++)
			swap(& matrix[i][j],& matrix[j][i]);
	return;
}



int main()
{
	int n = 5;
	int a[] = { 1, 2, 3, 4, 5};
	int b[] = {16,17,18,19, 6};
	int c[] = {15,24,25,20, 7};
	int d[] = {14,23,22,21, 8};
	int e[] = {13,12,11,10, 9};
	int* mat[5] = {a,b,c,d,e};
	
	display(mat,n,n);
	rotate(mat,n,n);
	display(mat,n,n);
	return 0;
}







