// �ǽ� 1 �迭�� �ε���

#include <iostream>
using namespace std;

void main()
{
	string Nation_name;
	string Nation[5] = { "Korea", "Japan", "China", "America", "Thiland" };
	int arraySize = sizeof(Nation) / sizeof(Nation[0]);
	bool Check = false;

	cout << "���� �̸��� �Է��Ͻÿ� , list �Է½� ���� ��� \n";
	cin >> Nation_name;

	if (Nation_name == "list")
	{
		for (int i = 0; i < arraySize; i++)
		{
			cout << Nation[i] << endl;
		}
	}

	else
	{
		for (int i = 0; i < arraySize; i++)
		{
			if (Nation_name == Nation[i])
			{
				Check = true;
				cout << i + 1 << ". " << Nation[i];
				break;
			}
		}
		if (Check == false)
		{
				cout << "�ش糪��� �����ϴ�";
		}
		
	}
}