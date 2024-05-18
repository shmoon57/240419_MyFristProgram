#include "Prac_review.h"
#include <iostream>
#include<string>
#include <vector>

#define NAME 0
#define AGE 1
#define BIRTHDAY 2

using namespace std;

namespace sh_func
{
	// �л� ���� ��� �Լ� , 2���� �����迭 �� Ȯ��
	void printStudentInfo(string** info, int student_count)
	{
		cout << "<�л� ������ ����մϴ�>" << endl << endl;
		cout << "�̸� ���� ����" << endl;

		for (int i = 0; i < student_count; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << info[i][j] << ' ';
			}
			cout << endl;
		}
	}

	// ��� ���� ��� �Լ�
	void PrintSumAge(string** info, int student_count)
	{
		int sum = 0;
		// ���� �� ���ϱ�
		for (int i = 0; i < student_count; i++)
		{
			sum = sum + stoi(info[i][AGE]);
		}

		cout << endl << "������ �� : " << sum << endl;
		cout << "��� ���� : " << float(sum / student_count) << endl; // �Ǽ������� ��ȯ
	}

	// ���� ���� ���� ��� �Լ�
	void PrintEarliestBirth(string** info, int student_count)
	{
		// 3-1) ���� ���Ҹ� ���� �� ���� birthday _ info ����
		vector<int>birthinfo(student_count);

		// 3-2) ���� ���Ҹ� ��� stoi�� �Ǽ����� ���������� ��ȯ	
		for (int i = 0; i < student_count; i++)
		{
			birthinfo[i] = stoi(info[i][BIRTHDAY]);
		}

		// 3-3) �ݺ������� �ּڰ��� ���� ������ ���� ���� ���Ұ� ���
		int fastest_birth = INT16_MAX;

		for (int i = 0; i < student_count; i++)
		{
			if (fastest_birth > birthinfo.at(i))
			{
				fastest_birth = birthinfo.at(i);
			}

		}
		cout << endl << "���� ���� ���� : " << fastest_birth << endl;

	}

	// �л� ���� ���� �Լ� (�̸����� �˻��Ͽ� ���� Ȥ�� ���� ����)
	void EditStudentInfo(string** info, int student_count)
	{
		string name;
		bool exit_edit = false;

		while (!exit_edit)
		{
			cout << endl << "������ �л��� �̸��� �Է����ּ��� (exit : ����) : ";
			cin >> name;

			// exit �Է����� ���� ����
			if (name == "exit")
			{
				cout << "������ �����մϴ� ! " << endl;
				break;
			}

			bool correct_name = false;

			for (int i = 0; i < student_count; i++)
			{

				if (info[i][0] == name)
				{
					correct_name = true;

					while (!exit_edit)
					{
						cout << endl << "� ������ �����Ͻðڽ��ϱ� ? (1 : ���� 2 : ���� 3 : ���� ����) : ";
						int edit_num;
						cin >> edit_num;

						// ���� ����
						if (edit_num == 1)
						{
							string new_age;
							cout << endl << "���ο� ���̸� �Է����ּ��� : ";
							cin >> new_age;
							info[i][1] = new_age;
							cout << "���̰� ���� �Ǿ����ϴ� !" << endl;
						}

						// ���� ����
						else if (edit_num == 2)
						{
							string new_birthday;
							cout << endl << "���ο� ������ �Է����ּ��� : ";
							cin >> new_birthday;
							info[i][2] = new_birthday;
							cout << "���̰� ���� �Ǿ����ϴ� !" << endl;
						}

						// ���� ����
						else if (edit_num == 3)
						{
							cout << "������ �����մϴ� ! " << endl;
							break;
						}

						else
						{
							cout << "�߸� �Է��߽��ϴ� ! " << endl;
						}
					}
				}

			}

			// exit �Է�, �ش�Ǵ� �̸� �Է� �̿��� ���
			if (name != "exit" && !correct_name)
			{
				cout << endl << "�ش�Ǵ� �̸��� �����ϴ�" << endl;
			}

		}
		cout << endl;
	}
}