// 실습 1 배열과 인덱스

// 국가 이름 배열로 만들고  list 입력시 내용 출력 , 
// 국가 이름 입력하면 , 인덱스와 내용 출력 , 국가이름 없을시  해당 나라 없다 출력 
// 데이터 정의 , 입력단 , 입력 판별 , 입력 처리

#include <iostream>
using namespace std;

void main()
{
	//데이터 정의
	string Nation[] = { "korea","japan","china","usa","spain" };
	string input;
	int arr_size = sizeof(Nation) / sizeof(Nation[0]);


	// 입력단
	cout << "list 입력시 해당 나라가 리스트 업 됩니다! " << endl;
	cout << "exit 입력시 종료! " << endl;
	while (1)
	{
		cout << endl << "나라 이름을 입력해주세요 " << endl;
		cout << "입력 : ";

		cin >> input;

		if (input == "exit")
		{
			break;
		}
		// 입력 판별(type)
		// 0 : 이외 1 : list 입력 2: 해당 국가 입력

		int type = 0;

		for (int i = 0; i < arr_size; i++)
		{
			if (input == "list")
			{
				type = 1;
			}
			else if (input == Nation[i])
			{
				type = 2;
			}
		}

		// 입력 처리

		switch (type)
		{
		case 0:
			cout << "해당 나라는 없습니다!" << endl;
			break;

		case 1:
			for (int i = 0; i < arr_size; i++)
			{
				cout << Nation[i] << endl;
			}
			break;

		case 2:
			for (int i = 0; i < arr_size; i++)
			{
				if (input == Nation[i])
				{
					cout << "인덱스 : " << i + 1 << ") " << Nation[i] << endl;
					break;
				}
			}
			break;

		}
	}


}


