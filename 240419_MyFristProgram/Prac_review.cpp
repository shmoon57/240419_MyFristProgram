// ���� �ǽ� + ���� �и� �߰�
/*
1. ����ڿ��� �� ���� �л��� �Է��� ������ ����
2. �л� �� ��ŭ �̸� - ���� - ���� ������ �ѹ��� �Է� �ޱ�
3. 4���� ��� ����
1) �л����� ���
2) ��� ����
3) ���� ���� ����
4) ���α׷� ����

// �ݺ��ؼ� ���ð���
// �Լ��� ��� ��� main �Լ� �����ϱ�
// �Է� �˻��ϱ� (���ڿ�, ����, ����, ������� ���)
// �л����� ����
// 2��° ��ɽ��� �� ��, 5) �׸� �߰�
// �̸�, ����, ����, ���� �߰� (column �߰�)
// ���� ��Ȳ Ȯ��

*/

#include <iostream>
#include <string>
#include <vector>
#include "Prac_review.h"

#define NAME 0
#define AGE 1
#define BIRTHDAY 2

using namespace std;

int main()
{
	// ������ ����
	int student_count;
	int sum_age = 0;

	while (true)
	{
		// �Է´�
		cout << "�� ���� �л� �����͸� �Է��Ͻðڽ��ϱ�? : ";
		cin >> student_count;
		cout << endl;

		if (student_count < 0) // ���� �۵� X
		{
			cout << "����� �Է����ּ���" << endl << endl;
		}
		else // ���� �۵��� ���
		{
			// 2���� ���� �迭 ����
			string** student_info_arr = new string * [student_count];

			for (int i = 0; i < student_count; i++)
			{
				student_info_arr[i] = new string[3];
			}

			// 2���� ���� �迭 �� �Ҵ�
			cout << "�̸� , ���� , ����(ex 9705) ������ �Է����ּ��� " << endl;

			for (int i = 0; i < student_count; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					cin >> student_info_arr[i][j]; // �̸� ���� ���� ������ �Է�
				}
			}

			cout << endl;

			// 1. �л� ���� ��� �Լ�  
			printStudentInfo(student_info_arr, student_count);

			// 2. ��� ���� ���ϱ�
			PrintSumAge(student_info_arr, student_count, sum_age);



			// 3. ���� ���� ���� ���ϱ�

			vector<int>birthday_info(student_count); // 3-1) ���� ���Ҹ� ���� �� ���� birthday _ info ����


			for (int i = 0; i < student_count; i++)
			{
				birthday_info[i] = stoi(student_info_arr[i][BIRTHDAY]); // 3-2) ���� ���Ҹ� ��� stoi�� �Ǽ����� ���������� ��ȯ		
			}

			// 3-3) �ݺ������� �ּڰ��� ���� ������ ���� ���� ���Ұ� ���
			int fastest_birth = INT16_MAX;

			for (int i = 0; i < student_count; i++)
			{
				if (fastest_birth > birthday_info.at(i))
				{
					fastest_birth = birthday_info.at(i);
				}

			}
			cout << endl << "���� ���� ���� : " << fastest_birth << endl;

			// 2���� ���� �迭 ����
			for (int i = 0; i < student_count; i++)
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


