// �ǽ� 2 string ����غ���

#include <iostream>
#include <string>

using namespace std;

void main()
{
	string input1;
	string input2;

	// ���� ���� �ľ� bool 
	bool i_1_has_word = false;
	bool i_2_has_word = false;

	while (true)
	{
		cout << "�� ���ڿ��� �Է����ּ���" << endl;

		cin >> input1 >> input2;
		cout << endl;

		// input 1 , 2 �ε��� ���� ������ ���� ���� �ľ� 
		for (int i = 0; i < input1.size(); i++)
		{
			if (isdigit(input1[i]) == 0)
			{
				i_1_has_word = true;
			}
		}

		for (int i = 0; i < input2.size(); i++)
		{
			if (isdigit(input2[i]) == 0)
			{
				i_2_has_word = true;
			}
		}

		if (i_1_has_word == false && i_2_has_word == false /*���� ����*/)
		{
			break;
		}
		else
		{
			cout << "�Է��� �߸� �Ǿ����ϴ�! ���ڸ� �Է����ּ���" << endl;
		}

		cout << endl;
	}
	
	// ��� ������ ��� �����
	cout << "�� ���ڸ� �̾� ���� ��� : " << input1 + input2 << endl; // �տ��� �Է� ���� �� ���ڸ� �̾� ���� ���

	
	cout << "�տ��� �Է� ���� �� ������ �� : " << stoi(input1) + stoi(input2) << endl; // �տ��� �Է� ���� �� ������ ���� ���

}



