#include "Prac_review.h"
#include <iostream>
#include<string>
#include <vector>

namespace sh_func
{

#define AGE 1

	using namespace std;

	void printStudentInfo(string** info, int count)// �л� ���� ��� �Լ� , 2���� �����迭 �� Ȯ��
	{
		cout << "<�л� ������ ����մϴ�>" << endl << endl;
		cout << "�̸� ���� ����" << endl;

		for (int i = 0; i < count; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << info[i][j] << ' ';
			}
			cout << endl;
		}
	}

	void PrintSumAge(string** info, int count, int sum)
	{
		for (int i = 0; i < count; i++)
		{
			sum = sum + stoi(info[i][AGE]); // ���� �� ���ϱ�
		}

		cout << endl << "������ �� :" << sum << endl;

		cout << "��� ���� : " << float(sum / count) << endl; // �Ǽ������� ��ȯ

	}
}