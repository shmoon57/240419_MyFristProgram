// ���� �迭

#include <iostream>
using namespace std;

int main()
{
	
	int num;
	int input_grade;
	int grade_sum = 0;
	float grade_avg;

	cout << "����� �л� ������ �Է��Ͻðڽ��ϱ�? ";
	cin >> num;
	

	int *grade = new int[num];

	for (int i = 0; i < num; i++)
	{
		cout << i + 1 << "�� �л��� ������ �Է��ϼ��� :" ;
		cin >> input_grade;
		grade[i] = input_grade;

		grade_sum = grade_sum + grade[i];
		
	}

	grade_avg = (float)grade_sum / (float)num;

	cout << "���� ��� : " << grade_avg;

	delete[] grade;
}