#include "Prac_review.h"
#include <iostream>
#include<string>
#include <vector>

namespace sh_func
{

#define AGE 1

	using namespace std;

	void printStudentInfo(string** info, int count)// 학생 정보 출력 함수 , 2차원 동적배열 값 확인
	{
		cout << "<학생 정보를 출력합니다>" << endl << endl;
		cout << "이름 나이 생일" << endl;

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
			sum = sum + stoi(info[i][AGE]); // 나이 합 구하기
		}

		cout << endl << "나이의 합 :" << sum << endl;

		cout << "평균 나이 : " << float(sum / count) << endl; // 실수형으로 변환

	}
}