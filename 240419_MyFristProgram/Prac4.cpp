#include <iostream>

// 2개의 변수와 연산자를 입력받아 계산할 수 있는 프로그램 만들기(Switch 문)


int main()
{
	float x;
	float y;
	char opr;


	std::cout << "실수 1을 입력하세요\n";
	std::cin >> x;

	std::cout << "실수 2를 입력하세요\n";
	std::cin >> y;

	std::cout << "어떤 연산을 하시겠습니까? 덧셈 : + 뺄셈 : - 곱셈 : * 나눗셈 : / ";
	std::cin >> opr;


	switch (opr)
	{
	case '+' :

		std::cout << x + y;// opr의 값이 + 일 경우 작동할 코드

		break;
	case '-':

		std::cout << x - y;// opr의 값이 - 일 경우 작동할 코드

		break;

	case '*':

		std::cout << x * y;// opr의 값이 * 일 경우 작동할 코드

		break;

	case '/':

		std::cout << x / y;// opr의 값이 / 일 경우 작동할 코드

		break;

	}

}