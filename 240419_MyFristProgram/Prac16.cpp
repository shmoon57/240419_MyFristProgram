// 2���� ���� �迭 240426
/*
1) ����ڷ� ���� x , y 2�� �ڿ��� �Է� �ޱ�
2) ����ڰ� x,y �� 0 or ���� �Է½� ���� �޽��� ��� �� ���Է� �ޱ�
3) x * y ũ�⸦ ���� ������ ���� �迭 arr ����
4) arr[0][0] ���� arr[x][y] ���� ������� 1���� x*y ����
5) arr[0][0] ���� arr[x][y] ���� ����� �� ���
*/

#include <iostream>
using namespace std;

void main()
{
	int x;
	int y;

	while (1)
	{
		// x , y 2�� �ڿ��� �Է� �ޱ�
		cout << "x�� �Է��ϼ��� : ";
		cin >> x;
		cout << "y�� �Է��ϼ��� : ";
		cin >> y;

		// 0 , ���� �Է½� �����޽��� ���
		if (x <= 0 || y <= 0)
		{
			cout << "x�� y ��� ����� �Է����ּ���.\n";
		}

		else
		{
			// x * y ũ�⸦ ���� ������ ���� �迭 arr ���� 
			int** arr = new int* [x];

			for (int i = 0; i < x; i++)
			{
				arr[i] = new int[y];
			}

			// arr[0][0] ���� arr[x][y] ���� ����� �� ���
			int num = 1;
			for (int i = 0; i < x; i++)
			{
				for (int j = 0; j < y; j++)
				{
					arr[i][j] = num;
					num++;
					cout << arr[i][j] << " ";
				}
				cout << endl;
			}

			for (int i = 0; i < x; i++)
			{
				delete[] arr[i];
			}
				delete[] arr;
				break;
		}


	}
}