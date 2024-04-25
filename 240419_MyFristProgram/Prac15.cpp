// 동적 배열

#include <iostream>
using namespace std;

int main()
{
	
	int num;
	int input_grade;
	int grade_sum = 0;
	float grade_avg;

	cout << "몇명의 학생 성적을 입력하시겠습니까? ";
	cin >> num;
	

	int *grade = new int[num];

	for (int i = 0; i < num; i++)
	{
		cout << i + 1 << "번 학생의 성적을 입력하세요 :" ;
		cin >> input_grade;
		grade[i] = input_grade;

		grade_sum = grade_sum + grade[i];
		
	}

	grade_avg = (float)grade_sum / (float)num;

	cout << "성적 평균 : " << grade_avg;

	delete[] grade;
}