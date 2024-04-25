// 실습 1 배열과 인덱스

#include <iostream>
using namespace std;

void main()
{
	string Nation_name;
	string Nation[5] = { "Korea", "Japan", "China", "America", "Thiland" };
	int arraySize = sizeof(Nation) / sizeof(Nation[0]);
	bool Check = false;

	cout << "나라 이름을 입력하시오 , list 입력시 내용 출력 \n";
	cin >> Nation_name;

	if (Nation_name == "list")
	{
		for (int i = 0; i < arraySize; i++)
		{
			cout << Nation[i] << endl;
		}
	}

	else
	{
		for (int i = 0; i < arraySize; i++)
		{
			if (Nation_name == Nation[i])
			{
				Check = true;
				cout << i + 1 << ". " << Nation[i];
				break;
			}
		}
		if (Check == false)
		{
				cout << "해당나라는 없습니다";
		}
		
	}
}