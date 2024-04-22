#include<iostream>

int main()
{
	int age;
	
	std::cout << "나이를 입력하세요\n";
	std::cin >> age;

	if (7 > age)
	{
		std::cout << "유아";
	}

	else if (13 >= age)
	{
		std::cout << "초등학생";
	}
	
	else if (16 >= age)
	{
		std::cout << "중학생";
	}
	
	else if (19 >= age)
	{
		std::cout << "고등학생";
	}

	else if (age >= 20)
	{
		std::cout << "성인";
	}

	else if (age >= 200)
	{
		std::cout << "나이가 너무 많습니다..!";
	}
}