// �ǽ� 1 �迭�� �ε���

// ���� �̸� �迭�� �����  list �Է½� ���� ��� , 
// ���� �̸� �Է��ϸ� , �ε����� ���� ��� , �����̸� ������  �ش� ���� ���� ��� 
// ������ ���� , �Է´� , �Է� �Ǻ� , �Է� ó��

#include <iostream>
using namespace std;

void main()
{
	//������ ����
	string Nation[] = { "korea","japan","china","usa","spain" };
	string input;
	int arr_size = sizeof(Nation) / sizeof(Nation[0]);


	// �Է´�
	cout << "list �Է½� �ش� ���� ����Ʈ �� �˴ϴ�! " << endl;
	cout << "exit �Է½� ����! " << endl;
	while (1)
	{
		cout << endl << "���� �̸��� �Է����ּ��� " << endl;
		cout << "�Է� : ";

		cin >> input;

		if (input == "exit")
		{
			break;
		}
		// �Է� �Ǻ�(type)
		// 0 : �̿� 1 : list �Է� 2: �ش� ���� �Է�

		int type = 0;

		for (int i = 0; i < arr_size; i++)
		{
			if (input == "list")
			{
				type = 1;
			}
			else if (input == Nation[i])
			{
				type = 2;
			}
		}

		// �Է� ó��

		switch (type)
		{
		case 0:
			cout << "�ش� ����� �����ϴ�!" << endl;
			break;

		case 1:
			for (int i = 0; i < arr_size; i++)
			{
				cout << Nation[i] << endl;
			}
			break;

		case 2:
			for (int i = 0; i < arr_size; i++)
			{
				if (input == Nation[i])
				{
					cout << "�ε��� : " << i + 1 << ") " << Nation[i] << endl;
					break;
				}
			}
			break;

		}
	}


}


