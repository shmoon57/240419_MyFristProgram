// 실습8 2차원 배열 복습 - 행렬 합

#include <iostream> 

using namespace std;

void main()
{
	int row;
	int col;
	int input_num;

	cout << "행과 열의 수를 입력하세요 : ";
	cin >> row >> col;

	// ro * col size 동적 배열(arr) 선언 
	int** matrix = new int* [row];

	for (int i = 0; i < row; i++)
	{
		matrix[i] = new int[col];
	}

	// 동적 배열 원소 값 할당
	cout << endl << "행렬 원소를 입력하세요 : " << endl;
	
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> input_num;
			matrix[i][j] = input_num;
		}

	}

	// 각 행의 합 구하기
	cout << endl << "각 행의 합 : " << endl;

	for (int i = 0; i < row; i++)
	{
		int row_sum = 0;
		cout << "행 " << i + 1 << ": ";
		for (int j = 0; j < col; j++)
		{
			row_sum = matrix[i][j] + row_sum;
		}
		cout << row_sum << endl;
	}

	// 각 열의 합 구하기
	cout << endl << "각 열의 합 : " << endl;

	for (int i = 0; i < row; i++)
	{
		int col_sum = 0;
		cout << "열 " << i + 1 << ": ";
		for (int j = 0; j < col; j++)
		{
			col_sum = matrix[i][j] + col_sum;
		}
		cout << col_sum << endl;
	}

	// 동적 배열 해제
	for (int i = 0; i < row; i++)
	{
		delete[] matrix[i];
	}
		delete[] matrix;

	}




