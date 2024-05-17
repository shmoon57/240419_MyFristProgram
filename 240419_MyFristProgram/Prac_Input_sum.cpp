// 실습 4 사용자가 입력한 숫자 더하기

#include <iostream>

int main()
{
	int num = 1;
	int sum = 0;

	std::cout << "사용자가 입력한 숫자 더하기\n\n";

	while (num != 0)
	{
		std::cout << "숫자를 입력하세요(0: exit)";

		std::cin >> num;
		sum = sum + num;

	}

	std::cout << "사용자가 입력한 수의 합은 : " << sum;

}