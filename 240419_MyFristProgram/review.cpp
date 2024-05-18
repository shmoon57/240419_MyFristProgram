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
	// 학생 정보 출력 함수 , 2차원 동적배열 값 확인
	void printStudentInfo(string** info, int student_count)
	{
		cout << "<학생 정보를 출력합니다>" << endl << endl;
		cout << "이름 나이 생일" << endl;

		for (int i = 0; i < student_count; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << info[i][j] << ' ';
			}
			cout << endl;
		}
	}

	// 평균 나이 출력 함수
	void PrintSumAge(string** info, int student_count)
	{
		int sum = 0;
		// 나이 합 구하기
		for (int i = 0; i < student_count; i++)
		{
			sum = sum + stoi(info[i][AGE]);
		}

		cout << endl << "나이의 합 : " << sum << endl;
		cout << "평균 나이 : " << float(sum / student_count) << endl; // 실수형으로 변환
	}

	// 가장 빠른 생일 출력 함수
	void PrintEarliestBirth(string** info, int student_count)
	{
		// 3-1) 생일 원소를 담을 빈 벡터 birthday _ info 생성
		vector<int>birthinfo(student_count);

		// 3-2) 생일 원소를 담고 stoi로 실수형을 정수형으로 변환	
		for (int i = 0; i < student_count; i++)
		{
			birthinfo[i] = stoi(info[i][BIRTHDAY]);
		}

		// 3-3) 반복문으로 최솟값을 구해 생일이 가장 빠른 원소값 출력
		int fastest_birth = INT16_MAX;

		for (int i = 0; i < student_count; i++)
		{
			if (fastest_birth > birthinfo.at(i))
			{
				fastest_birth = birthinfo.at(i);
			}

		}
		cout << endl << "가장 빠른 생일 : " << fastest_birth << endl;

	}

	// 학생 정보 수정 함수 (이름으로 검색하여 나이 혹은 생일 변경)
	void EditStudentInfo(string** info, int student_count)
	{
		string name;
		bool exit_edit = false;

		while (!exit_edit)
		{
			cout << endl << "편집할 학생의 이름을 입력해주세요 (exit : 종료) : ";
			cin >> name;

			// exit 입력으로 편집 종료
			if (name == "exit")
			{
				cout << "편집을 종료합니다 ! " << endl;
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
						cout << endl << "어떤 정보를 편집하시겠습니까 ? (1 : 나이 2 : 생일 3 : 편집 종료) : ";
						int edit_num;
						cin >> edit_num;

						// 나이 편집
						if (edit_num == 1)
						{
							string new_age;
							cout << endl << "새로운 나이를 입력해주세요 : ";
							cin >> new_age;
							info[i][1] = new_age;
							cout << "나이가 변경 되었습니다 !" << endl;
						}

						// 생일 편집
						else if (edit_num == 2)
						{
							string new_birthday;
							cout << endl << "새로운 생일을 입력해주세요 : ";
							cin >> new_birthday;
							info[i][2] = new_birthday;
							cout << "나이가 변경 되었습니다 !" << endl;
						}

						// 편집 종료
						else if (edit_num == 3)
						{
							cout << "편집을 종료합니다 ! " << endl;
							break;
						}

						else
						{
							cout << "잘못 입력했습니다 ! " << endl;
						}
					}
				}

			}

			// exit 입력, 해당되는 이름 입력 이외의 경우
			if (name != "exit" && !correct_name)
			{
				cout << endl << "해당되는 이름이 없습니다" << endl;
			}

		}
		cout << endl;
	}
}