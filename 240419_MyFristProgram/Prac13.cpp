// 실습 2 다차원 배열 

#include <iostream>
#define ROW_SIZE = 5;
#define COL_SIZE = 4; // 메모리 때문에
using namespace std;


int main()
{
	// 데이터 정의
	string name;
	int InputAge;
	string info[5][4] =
	{
		{"이름","나이","국어","수학"},
		{"방지턱","19","66","68"},
		{"정직한","20","73","94"},
		{"김가루","19","58","37"},
		{"조나단","20","82","29"}
	};

	// 입력단
	cout << "나이를 입력해주세요 : ";
	cin >> InputAge;

	//입력 판별
	// type 0 이외의 경우
	// type 1 : 19살
	// type 2 : 20살 

	int type = 0;

	if (InputAge == 19)
	{
		type = 1;
	}
	else if (InputAge == 20)
	{
		type = 2;
	}

	// 입력 처리

	switch (type)
	{
	case 0:
		cout << "해당 나이가 없습니다.";
		break;

	case 1:
	{
		cout << info[2, 1] << " : 국어 점수 : " << info[2, 3] << endl;
		cout << info[4, 1] << " : 국어 점수 : " << info[4, 3] << endl;
	}

	case 2:
	{
		cout << info[3, 1] << " : 국어 점수 : " << info[3, 3] << endl;
		cout << info[5, 1] << " : 국어 점수 : " << info[5, 3] << endl;
	}
	}
}
