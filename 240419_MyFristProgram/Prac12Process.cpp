#include <iostream>
using namespace std;

int main()
{

	// 0. ������ ����
	//
	string input;
	string city[] = { "�̱�", "����", "�ѱ�", "�Ϻ�", "�߱�" };
	int arrSize = sizeof(city) / sizeof(city[0]);

	cout << "list�� �Է��� ���� Ȯ���ϼ���." << endl;

	while (1) {

		// 1. �Է´�
		cout << " ~�����̸� ã���ִ� ����~" << endl;
		cout << " list : �����̸� ��ü ���" << endl;
		cout << " �����̸� �Է� : �ε��� ���" << endl;
		cout << " exit : ���α׷� ����" << endl;

		cout << endl << "�Է�: ";
		cin >> input;

		

		if (input == "exit")
		{
			break;
		}

		// 2. �Է� �Ǻ�
		//

		//
		//  type�� ����
		//  0 = �Է� ����
		//  1 = list ����
		//  2 = �����̸� ����
		//
		int type = 0;

		for (int i = 0; i < arrSize; i++)
		{
			if (input == "list")
			{
				type = 1;
			}
			else if (input == city[i])
			{
				type = 2;
			}
		}

		// 
		// 3. �Է� ó��
		// 
		switch (type)
		{
			// Error
		case 0:
			cout << "�����Դϴ�. �ٽ� �Է����ּ���." << endl;
			break;
			// list
		case 1:
			for (string country : city)
			{
				cout << country << endl;
			}
			break;
			// Country Name Match
		case 2:
			for (int i = 0; i < arrSize; i++)
			{
				if (input == city[i])
				{
					cout << "�ε���: " << i << ", �����̸�: " << city[i] << endl;
					break;
				}
			}
			break;
		}
	}
	return 0;
}