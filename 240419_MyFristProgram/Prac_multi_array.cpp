// �ǽ� 2 ������ �迭 
// ������ �迭 ����� 
// ���� �Է½� �̸� , �������� ���

#include <iostream>
#define ROW_SIZE 5
#define COL_SIZE 4 // �޸� ������
using namespace std;


int main()
{
	// ������ ����
	string name;
	string InputAge;
	string info[ROW_SIZE][COL_SIZE] =
	{
		{"�̸�","����","����","����"},
		{"������","19","66","68"},
		{"������","20","73","94"},
		{"�谡��","19","58","37"},
		{"������","20","82","29"}
	};

	// �Է´�
	cout << "���̸� �Է����ּ��� : ";
	cin >> InputAge;

	//�Է� �Ǻ�
	// type 0 �̿��� ���
	// type 1 : 19��
	// type 2 : 20�� 

	int type = 0;

	if (InputAge == "19")
	{
		type = 1;
	}
	else if (InputAge == "20")
	{
		type = 2;
	}

	// �Է� ó��

	switch (type)
	{
	case 0:
		cout << "�ش� ���̰� �����ϴ�.";
		break;

	case 1: // ���̰� 19��
	
		for (int i = 0; i < ROW_SIZE; i++)
		{
			for(int j= 0; j < COL_SIZE; j++)
			{
				if (j == 1)
				{
					if (info[i][j] == InputAge)
					{
						cout << info[i][0] << " " << info[i][3] << endl;
					}
				}
			}
		}
		break;
	

	case 2: // ���̰� 20��
	
		for (int i = 0; i < ROW_SIZE; i++)
		{
			for (int j = 0; j < COL_SIZE; j++)
			{
				if (j == 1)
				{
					if (info[i][j] == InputAge)
					{
						cout << info[i][0] << " " << info[i][3] << endl;
					}
				}
			}
		}
		break;
	}
}
