// �ǽ� 2 ������ �迭 

#include <iostream>
#define ROW_SIZE = 5;
#define COL_SIZE = 4; // �޸� ������
using namespace std;


int main()
{
	// ������ ����
	string name;
	int InputAge;
	string info[5][4] =
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

	if (InputAge == 19)
	{
		type = 1;
	}
	else if (InputAge == 20)
	{
		type = 2;
	}

	// �Է� ó��

	switch (type)
	{
	case 0:
		cout << "�ش� ���̰� �����ϴ�.";
		break;

	case 1:
	{
		cout << info[2, 1] << " : ���� ���� : " << info[2, 3] << endl;
		cout << info[4, 1] << " : ���� ���� : " << info[4, 3] << endl;
	}

	case 2:
	{
		cout << info[3, 1] << " : ���� ���� : " << info[3, 3] << endl;
		cout << info[5, 1] << " : ���� ���� : " << info[5, 3] << endl;
	}
	}
}
