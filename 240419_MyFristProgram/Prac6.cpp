// 반복문 구구단 5단 만들기
#include <iostream>

int main()
{
	int i;
	
	std::cout << "5단출력\n";

	for (i = 1; i <= 9; i++)
	{
		int k = 5 * i;
		std::cout << "\n5 * " << i << " = " << k;
	}

}