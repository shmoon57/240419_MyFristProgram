// ���� �ǽ�
/*
1. ����ڿ��� �� ���� �л��� �Է��� ������ ����
2. �л� �� ��ŭ �̸� - ���� - ���� ������ �ѹ��� �Է� �ޱ�
3. 4���� ��� ����
1) �л����� ���
2) ��� ����
3) ���� ���� ����
4) ���α׷� ����

�迭 ���
*/

#include <iostream>
#include <string>
#include <vector>

#define NAME 0
#define AGE 1
#define BIRTHDAY 2

using namespace std;

int main()
{
	// ������ ����
	int number;
	int sum_age = 0;

	/*string name;
	string age;
	string birthday;
	*/

	while (true)
	{
		// �Է´�
		cout << "�� ���� �л� �����͸� �Է��Ͻðڽ��ϱ�? : ";
		cin >> number;
		cout << endl;

		if (number <= 0)
		{
			cout << "����� �Է����ּ���" << endl << endl;
		}
		else
		{
			// 2���� ���� �迭 ����
			string** student_info_arr = new string * [number];

			for (int i = 0; i < number; i++)
			{
				student_info_arr[i] = new string[3];
			}

			// 2���� ���� �迭 �� �Ҵ�
			cout << "�̸� , ���� , ����(ex 9705) ������ �Է����ּ��� " << endl;

			for (int i = 0; i < number; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					cin >> student_info_arr[i][j]; // �̸� ���� ���� ������ �Է�
				}
			}

			cout << endl;

			// 2���� ���� �迭 �� Ȯ�� - �л� ���� ���
			cout << "<�л� ������ ����մϴ�>" << endl << endl;
			cout << "�̸� ���� �������" << endl;

			
			for (int i = 0; i < number; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					cout << student_info_arr[i][j] << ' ';
				}
				cout << endl;
			}

			// �迭 ���� ��� ���� ���ϱ�
			for (int i = 0; i < number; i++)
			{
				sum_age = sum_age + stoi(student_info_arr[i][AGE]);
			}

			cout << endl << "������ �� :" << sum_age << endl;

			cout << "��� ���� : " << float(sum_age / number) << endl;

			// ���� ���� ���� ���ϱ�

			vector<int>birthday_info(number); // ���� ���Ҹ� ���� �� ���� ����
			

			for (int i = 0; i < number; i++)
			{
				birthday_info[i] = stoi(student_info_arr[i][BIRTHDAY]); // ���� ���� ��� 			
			}

			int fastest_birth = INT16_MAX;

			for (int i = 0; i < number; i++)
			{
				if (fastest_birth > birthday_info.at(i))
				{
					fastest_birth = birthday_info.at(i);
				}

			}
			cout << endl << "���� ���� ���� : " << fastest_birth << endl;

			// 2���� ���� �迭 ����
			for (int i = 0; i < number; i++)
			{
				delete[] student_info_arr[i];
			}
			delete[] student_info_arr;
			
			break;
		}
	}

	// ���α׷� ���� 
	cout << endl << "���α׷��� �����ϰڽ��ϴ� ! ";
}