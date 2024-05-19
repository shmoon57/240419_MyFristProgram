#pragma once

#include<string>

using namespace std;

namespace sh_func
{
#ifndef _Print_
#define _Print_

	// �Է��� �̸��� �ѱ��̳� ���ĺ����� Ȯ���ϴ� �Լ�
	bool isName(string& str);
	
	// �Է��� ���̰� �������� Ȯ�� �ϴ� �Լ�
	bool isNumber(string& str);

	// �Է��� ������ YYMM ������ �´��� Ȯ���ϴ� �Լ� ���� �� isNumber()
	bool isYYMM(string& str);

	// 1. �л� ���� ��� �Լ� ����
	void printStudentInfo(string** info, int student_count);

	// 2. ��� ���� ��� �Լ� ����
	void PrintSumAge(string** info, int student_count);

	// 3. ���� ���� ���� ��� �Լ� ����
	void PrintEarliestBirth(string** info, int student_count);

	// 4. �л� ���� ���� �Լ�
	void EditStudentInfo(string** info, int student_count);

#endif 

}