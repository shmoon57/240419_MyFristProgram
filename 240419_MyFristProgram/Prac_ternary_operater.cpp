// 실습 5 삼항 연산자

#include <iostream>

int main()
{
	int num;

	std::cout << "숫자를 입력해주세요\n";
	std::cin >> num;

	num % 5 == 0 ? std::cout << "5의 배수입니다." : std::cout << "5의배수가 아니네요ㅜㅜ";

}