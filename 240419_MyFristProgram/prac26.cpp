// 종합 실습
/*
1. 사용자에게 몇 명의 학생을 입력할 것인지 묻기
2. 학생 수 만큼 이름 - 나이 - 생일 순으로 한번에 입력 받기
3. 4가지 기능 구현
1) 학생정보 출력
2) 평균 나이
3) 가장 빠른 생일
4) 프로그램 종료
*/

#include <iostream>
#include <string>
#include <vector>

#define NAME 0
#define AGE 1
#define BIRTHDAY 2

using namespace std;

void printStudentInfo(string** info, int count);

// 함수

int main()
{
	// 데이터 정의
	int student_count; 
	int sum_age = 0;
	
	while (true)
	{
		// 입력단
		cout << "몇 명의 학생 데이터를 입력하시겠습니까? : ";
		cin >> student_count;
		cout << endl;

		if (student_count < 0) // 정상 작동 X
		{
			cout << "양수를 입력해주세요" << endl << endl;
		}
		else // 정상 작동할 경우
		{
			// 2차원 동적 배열 선언
			string** student_info_arr = new string * [student_count];

			for (int i = 0; i < student_count; i++)
			{
				student_info_arr[i] = new string[3];
			}

			// 2차원 동적 배열 값 할당
			cout << "이름 , 나이 , 생일(ex 9705) 순서로 입력해주세요 " << endl;

			for (int i = 0; i < student_count; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					cin >> student_info_arr[i][j]; // 이름 나이 생일 순서로 입력
				}
			}

			cout << endl;

			// 1. 학생 정보 출력 - 2차원 동적 배열 값 확인 
			printStudentInfo(student_info_arr, student_count);

			// 2. 평균 나이 구하기
			for (int i = 0; i < student_count; i++)
			{
				sum_age = sum_age + stoi(student_info_arr[i][AGE]); // 나이 합 구하기
			}

			cout << endl << "나이의 합 :" << sum_age << endl;

			cout << "평균 나이 : " << float(sum_age / student_count) << endl; // 실수형으로 변환

			// 3. 가장 빠른 생일 구하기

			vector<int>birthday_info(student_count); // 3-1) 생일 원소를 담을 빈 벡터 birthday _ info 생성
			

			for (int i = 0; i < student_count; i++)
			{
				birthday_info[i] = stoi(student_info_arr[i][BIRTHDAY]); // 3-2) 생일 원소를 담고 stoi로 실수형을 정수형으로 변환		
			}

			// 3-3) 반복문으로 최솟값을 구해 생일이 가장 빠른 원소값 출력
			int fastest_birth = INT16_MAX;

			for (int i = 0; i < student_count; i++)
			{
				if (fastest_birth > birthday_info.at(i))
				{
					fastest_birth = birthday_info.at(i);
				}

			}
			cout << endl << "가장 빠른 생일 : " << fastest_birth << endl;

			// 2차원 동적 배열 해제
			for (int i = 0; i < student_count; i++)
			{
				delete[] student_info_arr[i];
			}
			delete[] student_info_arr;
			
			break;
		}
	}

	// 프로그램 종료 
	cout << endl << "프로그램을 종료하겠습니다 ! ";
}


void printStudentInfo(string** info, int count)
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