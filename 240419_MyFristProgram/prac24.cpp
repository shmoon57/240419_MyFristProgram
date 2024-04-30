// 실습 2 string 사용해보기

#include <iostream>
#include <string>

using namespace std;

void main()
{
	string input1;
	string input2;

	// 숫자 여부 파악 bool 
	bool i_1_has_word = false;
	bool i_2_has_word = false;

	while (true)
	{
		cout << "두 문자열을 입력해주세요" << endl;

		cin >> input1 >> input2;
		cout << endl;

		// input 1 , 2 인덱스 마다 글자의 숫자 여부 파악 
		for (int i = 0; i < input1.size(); i++)
		{
			if (isdigit(input1[i]) == 0)
			{
				i_1_has_word = true;
			}
		}

		for (int i = 0; i < input2.size(); i++)
		{
			if (isdigit(input2[i]) == 0)
			{
				i_2_has_word = true;
			}
		}

		if (i_1_has_word == false && i_2_has_word == false /*전부 숫자*/)
		{
			break;
		}
		else
		{
			cout << "입력이 잘못 되었습니다! 숫자만 입력해주세요" << endl;
		}

		cout << endl;
	}
	
	// 모두 숫자일 경우 실행됨
	cout << "두 숫자를 이어 붙인 결과 : " << input1 + input2 << endl; // 앞에서 입력 받은 두 숫자를 이어 붙인 출력

	
	cout << "앞에서 입력 받은 두 숫자의 합 : " << stoi(input1) + stoi(input2) << endl; // 앞에서 입력 받은 두 숫자의 합을 출력

}



