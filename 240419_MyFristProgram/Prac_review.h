#pragma once

#include<string>

using namespace std;

namespace sh_func
{
#ifndef _Print_
#define _Print_

	// 1. 학생 정보 출력 함수 선언
	void printStudentInfo(string** info, int student_count);

	// 2. 평균 나이 출력 함수 선언
	void PrintSumAge(string** info, int student_count);

	// 3. 가장 빠른 생일 출력 함수 선언
	void PrintEarliestBirth(string** info, int student_count);

	// 4. 학생 정보 수정 함수
	void EditStudentInfo(string** info, int student_count);

#endif 

}