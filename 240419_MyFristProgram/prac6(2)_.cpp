// 반복문 구구단 1 ~ 9 단 만들기
#include <iostream>

int main()
{
	int i;
	int j;
	std::cout << " 1~9 단출력\n";

	for (i = 1; i <= 9; i++)
	{
		std::cout << "-----" << i << "단------" << std::endl;

		for (j = 1; j <= 9; j++)
		{
				std::cout << i << " * " << j << " = " << i * j << std::endl ;

		}		
	}

}