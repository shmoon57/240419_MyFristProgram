// �ǽ�8 2���� �迭 ���� - ��� ��

#include <iostream> 

using namespace std;

void main()
{
	int row;
	int col;
	int input_num;

	cout << "��� ���� ���� �Է��ϼ��� : ";
	cin >> row >> col;

	// ro * col size ���� �迭(arr) ���� 
	int** matrix = new int* [row];

	for (int i = 0; i < row; i++)
	{
		matrix[i] = new int[col];
	}

	// ���� �迭 ���� �� �Ҵ�
	cout << endl << "��� ���Ҹ� �Է��ϼ��� : " << endl;
	
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> input_num;
			matrix[i][j] = input_num;
		}

	}

	// �� ���� �� ���ϱ�
	cout << endl << "�� ���� �� : " << endl;

	for (int i = 0; i < row; i++)
	{
		int row_sum = 0;
		cout << "�� " << i + 1 << ": ";
		for (int j = 0; j < col; j++)
		{
			row_sum = matrix[i][j] + row_sum;
		}
		cout << row_sum << endl;
	}

	// �� ���� �� ���ϱ�
	cout << endl << "�� ���� �� : " << endl;

	for (int i = 0; i < row; i++)
	{
		int col_sum = 0;
		cout << "�� " << i + 1 << ": ";
		for (int j = 0; j < col; j++)
		{
			col_sum = matrix[i][j] + col_sum;
		}
		cout << col_sum << endl;
	}

	// ���� �迭 ����
	for (int i = 0; i < row; i++)
	{
		delete[] matrix[i];
	}
		delete[] matrix;

	}




