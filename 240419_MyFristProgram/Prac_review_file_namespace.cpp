// 종합 실습 + 파일 분리 추가 + namespace 추가
/*
1. 사용자에게 몇 명의 학생을 입력할 것인지 묻기
2. 학생 수 만큼 이름 - 나이 - 생일 순으로 한번에 입력 받기
3. 4가지 기능 구현
1) 학생정보 출력 - 완료
2) 평균 나이 - 완료
3) 가장 빠른 생일 - 완료
4) 프로그램 종료 - 완료

// 반복해서 선택가능
// 함수로 기능 묶어서 main 함수 정리하기 - 완료
// 입력 검사하기 (문자열, 숫자, 길이, 생년월일 양식) - 완료
// 학생정보 수정 - 완료
// 2번째 기능실행 될 때
// 이름, 나이, 생일, 과목 추가 (column 추가)
// 과목별 현황 확인

// 실습 namespace 사용하기 - 완료
// 1. 앞서 만들었던 헤더 파일을 main함수가 있는 파일에서 불러오기
// 2. 앞서 만들었던 헤더 파일에 있는 내용을 적절한 namespace 이름으로 감싸기
// 3. main 함수가 있는 파일에서 헤더에 있는 내용을 namespace를 거쳐서 사용하기

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
	// 데이터 정의
	int student_count;

	while (true)
	{
		// 입력단
		cout << "몇 명의 학생 데이터를 입력하시겠습니까? : ";
		cin >> student_count;
		cout << endl;

		// 정상 작동 
		if (student_count > 0)
		{
			// 2차원 동적 배열 선언
			string** student_info_arr = new string * [student_count];

			for (int i = 0; i < student_count; i++)
			{
				student_info_arr[i] = new string[3];
			}

			// 2차원 동적 배열 값 할당
			cout << "이름, 나이, 생일(ex 9705) 순서로 입력해주세요 " << endl;

			
			for (int i = 0; i < student_count; i++)
			{
				// 이름 입력
				while (true)
				{
					cout << "학생 " << i + 1 << " 이름  : ";
					cin >> student_info_arr[i][NAME];

					if (sh_func::isName(student_info_arr[i][NAME]))
					{
						break;
					}

					else
					{
						cout << "잘못된 이름 형식입니다. 다시 입력해주세요." << endl;
					}
				}

				// 나이 입력
				while (true)
				{
					cout << "학생 " << i + 1 << "의 나이: ";
					cin >> student_info_arr[i][AGE];

					if (sh_func::isNumber(student_info_arr[i][AGE])) {
						break;
					}
					else {
						cout << "잘못된 나이 형식입니다. 숫자로 다시 입력해주세요." << endl;
					}
				}

				// 생일 입력
				while (true)
				{
					cout << "학생 " << i + 1 << "의 생일(예: 9705): ";
					cin >> student_info_arr[i][BIRTHDAY];

					if (sh_func::isYYMM(student_info_arr[i][BIRTHDAY]))
					{
						break;
					}
					else {
						cout << "잘못된 생일 형식입니다. YYMM 형식으로 다시 입력해주세요." << endl;
					}
				}
			}

			cout << endl;

			// 1. 학생 정보 출력 함수  
			sh_func::printStudentInfo(student_info_arr, student_count);

			// 2. 평균 나이 출력 함수
			sh_func::PrintSumAge(student_info_arr, student_count);

			// 3. 가장 빠른 생일 출력 함수
			sh_func::PrintEarliestBirth(student_info_arr, student_count);

			// 4. 학생 정보 수정 함수
			sh_func::EditStudentInfo(student_info_arr, student_count);
			// 바뀐 학생 정보 출력  
			sh_func::printStudentInfo(student_info_arr, student_count);

			// 2차원 동적 배열 해제
			for (int i = 0; i < student_count; i++)
			{
				delete[] student_info_arr[i];
			}

			delete[] student_info_arr;
			break;

		}

		else // 정상 작동 X
		{
			cout << "잘못된 값을 입력했습니다 ! " << endl << "양수를 입력해주세요" << endl << endl;
		}

	}

	// 프로그램 종료 
	cout << endl << "프로그램을 종료하겠습니다 ! " << endl;
}


