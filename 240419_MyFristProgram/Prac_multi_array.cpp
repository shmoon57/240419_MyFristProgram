// 실습 2 다차원 배열 
// 다차원 배열 만들기 
// 나이 입력시 이름 , 국어점수 출력

#include <iostream>
#define ROW_SIZE 5
#define COL_SIZE 4 // 메모리 때문에
using namespace std;


int main()
{
	// 데이터 정의
	string name;
	string InputAge;
	string info[ROW_SIZE][COL_SIZE] =
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

	if (InputAge == "19")
	{
		type = 1;
	}
	else if (InputAge == "20")
	{
		type = 2;
	}

	// 입력 처리

	switch (type)
	{
	case 0:
		cout << "해당 나이가 없습니다.";
		break;

	case 1: // 나이가 19살
	
		for (int i = 0; i < ROW_SIZE; i++)
		{
			for(int j= 0; j < COL_SIZE; j++)
			{
				if (j == 1)
				{
					if (info[i][j] == InputAge)
					{
						cout << info[i][0] << " " << info[i][3] << endl;
					}
				}
			}
		}
		break;
	

	case 2: // 나이가 20살
	
		for (int i = 0; i < ROW_SIZE; i++)
		{
			for (int j = 0; j < COL_SIZE; j++)
			{
				if (j == 1)
				{
					if (info[i][j] == InputAge)
					{
						cout << info[i][0] << " " << info[i][3] << endl;
					}
				}
			}
		}
		break;
	}
}
