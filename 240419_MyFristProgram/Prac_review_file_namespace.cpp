// ���� �ǽ� + ���� �и� �߰� + namespace �߰�
/*
1. ����ڿ��� �� ���� �л��� �Է��� ������ ����
2. �л� �� ��ŭ �̸� - ���� - ���� ������ �ѹ��� �Է� �ޱ�
3. 4���� ��� ����
1) �л����� ��� - �Ϸ�
2) ��� ���� - �Ϸ�
3) ���� ���� ���� - �Ϸ�
4) ���α׷� ���� - �Ϸ�

// �ݺ��ؼ� ���ð���
// �Լ��� ��� ��� main �Լ� �����ϱ� - �Ϸ�
// �Է� �˻��ϱ� (���ڿ�, ����, ����, ������� ���)
// �л����� ����
// 2��° ��ɽ��� �� ��, 5) �׸� �߰�
// �̸�, ����, ����, ���� �߰� (column �߰�)
// ���� ��Ȳ Ȯ��

// �ǽ� namespace ����ϱ�
// 1. �ռ� ������� ��� ������ main�Լ��� �ִ� ���Ͽ��� �ҷ�����
// 2. �ռ� ������� ��� ���Ͽ� �ִ� ������ ������ namespace �̸����� ���α�
// 3. main �Լ��� �ִ� ���Ͽ��� ����� �ִ� ������ namespace�� ���ļ� ����ϱ�

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

	while (true)
	{
		// �Է´�
		cout << "�� ���� �л� �����͸� �Է��Ͻðڽ��ϱ�? : ";
		cin >> student_count;
		cout << endl;

		// ���� �۵� 
		if (student_count > 0) 
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
			sh_func::printStudentInfo(student_info_arr, student_count);

			// 2. ��� ���� ��� �Լ�
			sh_func::PrintSumAge(student_info_arr, student_count);

			// 3. ���� ���� ���� ��� �Լ�
			sh_func::PrintEarliestBirth(student_info_arr, student_count);

			// 4. �л� ���� ���� �Լ�
			sh_func::EditStudentInfo(student_info_arr, student_count);
			// �ٲ� �л� ���� ���  
			sh_func::printStudentInfo(student_info_arr, student_count);

			// 2���� ���� �迭 ����
			for (int i = 0; i < student_count; i++)
			{
				delete[] student_info_arr[i];
			}

			delete[] student_info_arr;
			break;
			
		}

		else // ���� �۵� X
		{
			cout << "�߸��� ���� �Է��߽��ϴ� ! " << endl << "����� �Է����ּ���" << endl << endl;
		}

	}

	// ���α׷� ���� 
	cout << endl << "���α׷��� �����ϰڽ��ϴ� ! " << endl;
}


