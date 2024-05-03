#pragma once

#include<string>

using namespace std;

#ifndef _Print_
#define _Print_

/*중복 선언되면 안되는 코드들*/

// 1. 학생 정보 출력 함수  선언
void printStudentInfo(string** info, int count);

// 2. 평균 나이 구하는 함수 선언
void PrintSumAge(string** info, int count, int sum);

#endif 